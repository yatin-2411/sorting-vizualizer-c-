#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <chrono>
#include <conio.h>
#include <thread>

#define _WIN32_WINNT 0x0500
#include<windows.h>


// ascii codes
#define zn 219

#define green 2
#define white 15
#define red 4
#define purple 5
#define gray 8
#define blackWhite 240

void scp(int x, int y)
{
    COORD coords = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);
}

std::string frame[23]
{
    " **************************************************************************************** ",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    "*                                                                                        *",
    " **************************************************************************************** ",
};

std::string MainMenuFrame[23]
{
    " ***************************************************************************************************************************",
    "*                                      Sorting Vizualizer ASCII                                                              *",
    "*                                      ***********************************************                                       *",
    "*                                    *                                                 *                                     *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                  *                                                    *                                    *",
    "*                                   *                                                  *                                     *",
    "*                                    **************************************************                                      *",
    " ****************************************************************************************************************************",
};


std::string infoFrame[23]
{
    " ********************************* ",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "* Wszytskie elementy:             *",
    "* Elementy posortowane:           *",
    "* Aktualny czas:                  *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    "*                                 *",
    " ********************************* ",
};

std::string MainMenuOptions[4] =
{
    "Bubble Sort       ",
    "Insertion Sort    ",
    "Selection Sort    ",
    "Quick Sort        ",
};


class mRectangle
{
public:
    int xCoord;
    int height;

    void DrawRectangle()
    {
        int currentY = 20;
        for(int i=0; i<height; i++)
        {
            scp(xCoord, currentY - i);
            std::cout << char(zn) << char(zn);
        }
    }
};


void fillRectangleVector(std::vector<mRectangle> &rectangles, int Min, int Max, int Size);
std::pair<int, int> GetInfoAbautCurrentStateOfConsole();

void BubbleSort(std::vector<mRectangle> &rectagles);
void SelectionSort(std::vector<mRectangle> &rectangles);
void InsertionSort(std::vector<mRectangle> &rectangles);
void DrawRectangleVcetor(std::vector<mRectangle> rectangles);
void refresh(mRectangle rec1, mRectangle rec2, int color1, int color2);
void writeFrame();
void ShowColors();
void writeInforFrame();
void PaintOneRectangle(mRectangle rectangle, int color);
void writeMainMenuFrame();
int QestionAboutSize();
void WriteMainMenuOptios();
void ShowConsoleCursor(bool showFlag);
void WaitingFromQ(int x, int y);


int CurrentMenuOptionChooseY = 6;
void SelectMainMenuOptionEvent();


int main()
{
    srand(time(NULL));
    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    ShowConsoleCursor(false);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);




    writeMainMenuFrame();
    WriteMainMenuOptios();
    SelectMainMenuOptionEvent();

    scp(10, 25);
    system("pause");








    //DrawRectangleVcetor(rectangles);





    // zielony 2
    // czerwony 4
    // bialy 15

    //ShowColors();

    while(1) {}


    return 0;
}

void fillRectangleVector(
    std::vector<mRectangle> &rectangles, int Min, int Max, int Size)
{
    int xOffSet = 1;
    for(int i=0; i<Size; i++)
    {
        mRectangle rec;
        rec.height = Min + std::rand()%(Max - Min + 1);
        rec.xCoord = xOffSet;

        rectangles.push_back(rec);

        xOffSet += 3;
    }
}

std::pair<int, int> GetInfoAbautCurrentStateOfConsole()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    std::pair<int, int> result;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    result.first = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    result.second = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return result;
}

void BubbleSort(std::vector<mRectangle> &rectagles)
{
    writeFrame();
    writeInforFrame();

    scp(93, 3);
    std::cout << "Babelkowe";

    scp(118, 7);
    std::cout << rectagles.size();

    scp(118, 8);
    std::cout << 0;

    scp(118, 9);
    std::cout << 0.0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
    DrawRectangleVcetor(rectagles);

    bool isSwapped;
    int unsortedElements = rectagles.size();
    int Sorted = 0;

    do
    {
        isSwapped = false;
        for(int i = 0; i < unsortedElements - 1; i++)
        {
            if(rectagles[i].height > rectagles[i+1].height &&
                    rectagles[i].xCoord < rectagles[i+1].xCoord)
            {
                refresh(rectagles[i], rectagles[i+1], red, green);

                int temp = rectagles[i].height;
                rectagles[i].height = rectagles[i+1].height;
                rectagles[i+1].height = temp;

                isSwapped = true;


                DrawRectangleVcetor(rectagles);
            }
        }

        Sorted++;
        unsortedElements--;

        scp(118, 8);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
        std::cout << Sorted;


    }
    while(isSwapped == true);

    scp(118, 8);
    std::cout << rectagles.size();

    WaitingFromQ(3, 24);
}




void SelectionSort(std::vector<mRectangle> &rectangles)
{
    writeFrame();
    writeInforFrame();

    scp(93, 3);
    std::cout << "Przez Wybor";

    scp(118, 7);
    std::cout << rectangles.size();

    scp(118, 8);
    std::cout << 0;

    scp(118, 9);
    std::cout << 0.0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
    DrawRectangleVcetor(rectangles);

    int minIndex;
    int arrSize = rectangles.size();
    for(int i = 0; i < arrSize - 1; i++)
    {
        minIndex = i;
        for(int j = i + 1; j < arrSize; j++)
        {
            if(rectangles[j].height < rectangles[minIndex].height)
            {
                minIndex = j;
            }
        }

        refresh(rectangles[i], rectangles[minIndex], green, red);

        int temp = rectangles[minIndex].height;
        rectangles[minIndex].height = rectangles[i].height;
        rectangles[i].height = temp;

        PaintOneRectangle(rectangles[i], 5);

        Sleep(100);

        //system("cls");
        //DrawRectangleVcetor(rectangles);
    }
    PaintOneRectangle(rectangles[rectangles.size() - 1], purple);


    scp(118, 8);
    std::cout << rectangles.size();

    WaitingFromQ(3, 24);
}






void InsertionSort(std::vector<mRectangle> &rectangles)
{
    writeFrame();
    writeInforFrame();

    scp(93, 3);
    std::cout << "Przez Wstawianie";

    scp(118, 7);
    std::cout << rectangles.size();

    scp(118, 8);
    std::cout << 0;

    scp(118, 9);
    std::cout << 0.0;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), green);
    DrawRectangleVcetor(rectangles);

    for(int i=0; i<rectangles.size(); i++)
    {
        mRectangle refValue = rectangles[i];
        int j;

        for(j = i - 1; j >= 0; j--)
        {
            if(rectangles[j].height > refValue.height)
            {
                //refresh(rectangles[j], rectangles[j+1], green, red);
                rectangles[j+1].height = rectangles[j].height;
                //PaintOneRectangle(rectangles[j+1], red);
            }else
                break;
        }

        //refresh(refValue, rectangles[j+1], green, red);
        rectangles[j+1].height = refValue.height;

        //system("cls");
        refresh(refValue, rectangles[j+1], green, red);




    }

    DrawRectangleVcetor(rectangles);



    PaintOneRectangle(rectangles[rectangles.size() - 1], purple);


    scp(118, 8);
    std::cout << rectangles.size();

    WaitingFromQ(3, 24);
}





void refresh(mRectangle rec1, mRectangle rec2, int color1, int color2)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int difference = std::abs(rec1.height - rec2.height);
    int currentY = 20 - rec2.height;

    SetConsoleTextAttribute(handle, color1);
    for(int i=0; i<rec1.height; i++)
    {
        scp(rec1.xCoord, 20 - i);
        std::cout << char(zn) << char(zn);
    }

    for(int i=0; i<rec2.height; i++)
    {
        scp(rec2.xCoord, 20 - i);
        std::cout << char(zn) << char(zn);
    }

    Sleep(10);

    for(int i=0; i<difference; i++)
    {
        scp(rec1.xCoord, currentY - i);
        std::cout << "  ";

        SetConsoleTextAttribute(handle, color1);
        scp(rec2.xCoord, currentY - i);
        std::cout << char(zn) << char(zn);
        SetConsoleTextAttribute(handle, color2);
    }

    SetConsoleTextAttribute(handle, color2);

}

void DrawRectangleVcetor(std::vector<mRectangle> rectangles)
{
    for(int i=0; i<rectangles.size(); i++)
    {
        rectangles[i].DrawRectangle();
    }
}

void writeFrame()
{
    scp(0,0);
    for(int i=0; i<23; i++)
    {
        std::cout << frame[i] << std::endl;
    }
}

void ShowColors()
{
    for(int color = 1; color < 300; color++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
        std::cout << color << " hello world\n";
    }
}

void writeInforFrame()
{
    int currentY = 0, currentX = 91;
    for(int i=0; i<23; i++)
    {
        scp(currentX, currentY);
        std::cout << infoFrame[i];

        currentY++;
    }

    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    scp(93, 2);
    SetConsoleTextAttribute(handle, gray);
    std::cout << "ALGORYTM SORTOWANIA";
    SetConsoleTextAttribute(handle, white);
}

void writeMainMenuFrame()
{
    scp(0,0);
    for(int i=0; i<23; i++)
    {
        std::cout << MainMenuFrame[i] << std::endl;
    }
}

void PaintOneRectangle(mRectangle rectangle, int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int currentY = 20;

    for(int i=0; i < rectangle.height; i++)
    {
        scp(rectangle.xCoord, 20 - i);
        SetConsoleTextAttribute(handle, color);
        std::cout << char(zn) << char(zn);
    }

    SetConsoleTextAttribute(handle, white);
}

int QestionAboutSize()
{
    writeFrame();
    writeInforFrame();
    int Size = 0;
    scp(3, 3);
    std::cout << "ile elementow chcesz sortowac: ";
    std::cin >> Size;


    return Size;
}

void WriteMainMenuOptios()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    int currentX = 53, currentY = 5;

    scp(currentX, currentY);
    SetConsoleTextAttribute(handle, gray);
    std::cout << "  Sorting algorithms";
    SetConsoleTextAttribute(handle, white);

    currentY++;
    for(int i=0; i<4; i++)
    {
        scp(currentX, currentY);
        if(currentY == CurrentMenuOptionChooseY)
        {
            SetConsoleTextAttribute(handle, blackWhite);
            std::cout << char(16) << " " << MainMenuOptions[i];
            SetConsoleTextAttribute(handle, white);

            currentY++;
            continue;
        }
        std::cout << char(16) << " " << MainMenuOptions[i];

        currentY++;
    }

    currentY += 2;

    SetConsoleTextAttribute(handle, gray);
    scp(currentX, currentY);
    std::cout << "   Other option";
    currentY++;
    scp(currentX, currentY);

    if(currentY == CurrentMenuOptionChooseY)
        SetConsoleTextAttribute(handle, blackWhite);
    else
        SetConsoleTextAttribute(handle, white);
    std::cout << char(16) << "  Exit         ";


    currentY++;
    scp(currentX, currentY);

    if(currentY == CurrentMenuOptionChooseY)
        SetConsoleTextAttribute(handle, blackWhite);
    else
        SetConsoleTextAttribute(handle, white);
    std::cout << char(16) << "  About program";
}

void SelectMainMenuOptionEvent()
{
    char input;
    while(true)
    {
        input = getch();
        if(input == 'w' && CurrentMenuOptionChooseY > 6)
        {

            if(CurrentMenuOptionChooseY == 13)
            {
                CurrentMenuOptionChooseY -= 4;
                WriteMainMenuOptios();
                continue;
            }
            CurrentMenuOptionChooseY--;
            WriteMainMenuOptios();
        }
        else if(input == 's' && CurrentMenuOptionChooseY < 14)
        {
            if(CurrentMenuOptionChooseY == 9)
            {
                CurrentMenuOptionChooseY += 4;
                WriteMainMenuOptios();
                continue;
            }
            CurrentMenuOptionChooseY++;
            WriteMainMenuOptios();
        }
        else if(input == 'e')
        {
            std::vector<mRectangle> rectangles;
            int SizeOfVector = QestionAboutSize();
            fillRectangleVector(*&rectangles, 1, 20, SizeOfVector);

            if(CurrentMenuOptionChooseY == 6)
            {
                BubbleSort(*&rectangles);
            }
            else if(CurrentMenuOptionChooseY == 7)
            {
                SelectionSort(rectangles);
            }
            else if(CurrentMenuOptionChooseY == 8)
            {
                InsertionSort(rectangles);
            }


            writeMainMenuFrame();
            WriteMainMenuOptios();
            SelectMainMenuOptionEvent();


            //BubbleSort(*&rectangles);
            //SelectionSort(rectangles);
        }
    }
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void WaitingFromQ(int x, int y)
{
    scp(x, y);
    char input;
    std::cout << "nacisnij q aby przejsc do menu glownego";
    while(true)
    {
        input = getch();
        if(input == 'q')
            break;
    }

    scp(x, y);
    std::cout << "                                         ";
}

