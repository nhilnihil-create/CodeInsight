#include <iostream>
using namespace std;
int main() {
	int c[3][3];
	int a[3];
	int b[3];
	int min;
	bool flag = false;
	for (int a = 0;a < 3;a ++) {
		for (int b = 0;b < 3;b++)
			cin >> c[a][b];
	}//数値の格納
	min = c[0][0];
	for (int d = 1;d < 3;d++) {
		if (c[0][d] < min)
			min = c[0][d];
	}//minを定義
	for (a[0] = 0;a[0] <= min;a[0]++) {
		for (int i = 0;i < 3;i++) {
			b[i] = c[0][i] - a[0];
		}
		a[1] = c[1][0] - b[0];
		a[2] = c[2][0] - b[0];
		if (a[1] + b[1] == c[1][1] && a[1] + b[2] == c[1][2] && a[2]+b[1]==c[2][1] && a[2]+b[2]==c[2][2]) {
			flag = true;
			break;
		}
		

	}
	if (flag)
		cout << "Yes";
	else cout << "No";
}