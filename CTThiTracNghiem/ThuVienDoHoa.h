#include<stdio.h>
#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<conio.h>
using namespace std;
void gotoxy(short x,short y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x,y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}
//to mau BG
void SetBGColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    color <<= 4;
    wAttributes &= 0xff0f;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

int wherey()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.Y;
}
//to mau
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// man hinh loading
void manHinhLoading()
{
	system("cls");

	gotoxy(75,18);cout << "LOADING...";
	for( int i = 0 ; i <= 50 ; i++ ){
		textcolor(9);
		gotoxy(53 + i,19);cout << char(219);
		textcolor(3);
		gotoxy(77,20);cout << i * 2 << "%";
			Sleep(30);
		}
}

int wherex()
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    return screen_buffer_info.dwCursorPosition.X;
}

//Ham thay doi kich co cua khung console voi tham so truyen vao la chieu cao, chieu rong.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void SetWindowSize(SHORT width, SHORT height)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT WindowSize;
    WindowSize.Top = 0;
    WindowSize.Left = 0;
    WindowSize.Right = width;
    WindowSize.Bottom = height;
    SetConsoleWindowInfo(hStdout, 1, &WindowSize);
}

// khung cau hoi
void KhungCauHoi(){
	textcolor(11);
	gotoxy(20, 7);cout << char(201); //Thanh Tren
	for(int i = 0; i < 120 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(20,8);cout << char(186); //10
	gotoxy(141, 8);cout << char(186); // 
	gotoxy(20,9);cout << char(186);
	gotoxy(141,9);cout << char(186); // 48
	gotoxy(141,10);cout << char(186);
	gotoxy(20,10);cout << char(186);
	gotoxy(20,11);cout << char(200);
	for(int i = 0; i < 120 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
//khung dap an A
void KhungTraLoiTraiTren(){
	textcolor(6);
	gotoxy(25, 15);cout << char(201); //34
	for(int i = 0; i < 45 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(25,16);cout << char(186); //10
	gotoxy(71,16);cout << char(186); // 
	gotoxy(25,17);cout << char(186);
	gotoxy(71,17);cout << char(186); // 48
	gotoxy(71,18);cout << char(186);
	gotoxy(25,18);cout << char(186);
	gotoxy(25,19);cout << char(200);
	for(int i = 0; i < 45 ; i++){
		cout << char(205);
	}
	cout << char(188);
}

//khung dap an C
void KhungTraLoiTraiDuoi(){
	textcolor(6);
	gotoxy(25, 23);cout << char(201); //34
	for(int i = 0; i < 45 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(25,24);cout << char(186); 
	gotoxy(71, 24);cout << char(186); 
	gotoxy(25,25);cout << char(186);
	gotoxy(71,25);cout << char(186); 
	gotoxy(71,26);cout << char(186);
	gotoxy(25,26);cout << char(186);
	gotoxy(25,27);cout << char(200);
	for(int i = 0; i < 45 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
//khung dap an B
void KhungTraLoiPhaiTren(){
	textcolor(6);
	gotoxy(90, 15);cout << char(201); //34
	for(int i = 0; i < 45 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(90,16);cout << char(186); //10
	gotoxy(136,16);cout << char(186); // 
	gotoxy(90,17);cout << char(186);
	gotoxy(136,17);cout << char(186); // 48
	gotoxy(136,18);cout << char(186);
	gotoxy(90,18);cout << char(186);
	gotoxy(90,19);cout << char(200);
	for(int i = 0; i < 45 ; i++){
		cout << char(205);
	}
	cout << char(188);
}
//khung dap an D
void KhungTraLoiBenPhaiDuoi(){
	textcolor(6);
	gotoxy(90, 23);cout << char(201); //46
	for(int i = 0; i < 45 ; i++){ // chieu rong cua bang 18
		cout << char(205);
	}
	cout << char(187);
	gotoxy(90,24);cout << char(186); //10
	gotoxy(136,24);cout << char(186); // 
	gotoxy(90,25);cout << char(186);
	gotoxy(136,25);cout << char(186); // 48
	gotoxy(136,26);cout << char(186);
	gotoxy(90,26);cout << char(186);
	gotoxy(90,27);cout << char(200);
	for(int i = 0; i < 45 ; i++){
		cout << char(205);
	}
	cout << char(188);
}


//Tao Khung Vien
void khungVien()
{
	 int i,j;
 
 for(i=10;i<150;i++) // tao dong ngang
  {
  gotoxy(i,1);
  	printf("%c",205); // dong ngang tren
  gotoxy(i,36);
  	printf("%c",205);  // dong ngang duoi
  }
  for(j=2;j<36;j++)  // dong ke thang dung
  {
  gotoxy(10,j);
  	printf("%c",186); // dong thang ben trai
  gotoxy(150,j);
 	printf("%c",186);// dong thang ben phai
  }
  gotoxy(150,1);
  	printf("%c",187); // cai moc cau ben phai ben tre^n
  gotoxy(150,36);
  	printf("%c",188); // cai moc cau ben phai ben duoi
  gotoxy(10,1);
  	printf("%c",201); // cai moc cau ben trai tren
  gotoxy(10,36);
  	printf("%c",200); // moc cau ben trai duoi
}

