#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int total,A,B,C,X,Y,temp;

void func(int x,int temp,int C,int &total) {
	//cout << x << temp << endl;
	//cout << C << endl;
	int temp_x = temp * x;
	int temp_C = temp * C * 2;
	//cout << temp_x << temp_C << endl;
	if (temp_x > temp_C) {
		total += temp_C;
		//cout << temp_C << endl;
		//cout << total << endl;
	}
	else {
		total += temp_x;
		//cout << temp_x << endl;
		//cout << total << endl;
	}
}

int main() {
	//入力
	int A = 0, B = 0, C = 0, X = 0, Y = 0;
	cin >> A >> B >> C >> X >> Y;
	int total = 0;
	//処理
	if (A + B > C * 2) {
		if (X > Y) {
			total += C * Y * 2;//1600 * 2 * 2 = 6400
			int temp = X - Y;//1
			/*
			if (temp * A > temp * C) {
				total += temp * C;
			}
			else {
				total += temp * A;
			}
			*/
			func(A,temp,C,total);
		}
		else {
			total += C * X * 2;
			int temp = Y - X;
			/*
			if (temp * B > temp* C) {
				total += temp * C;
			}
			else {
				total += temp * B;
			}
			*/
			func(B, temp,C,total);
		}
	}
	else {
		if (X > Y) {
			total += A * Y + B * Y;
			int temp = X - Y;
			func(A, temp, C, total);
		}
		else {
			total += A * X + B * X;
			int temp = Y - X;
			func(B, temp, C, total);

		}
	}

	//出力
	cout << total << endl;

}