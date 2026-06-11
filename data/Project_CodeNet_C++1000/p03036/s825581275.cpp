#include <iostream>
using namespace std;

int main() {
	int r; //2<=r<=5
	int d; //1<=d<=100
	int x2000; //西暦2000年になる瞬間に生えている重さの合計 d<=x2000<=200
	int next_x;

	cin >> r >> d >> x2000;

	next_x = x2000;
	for (int i = 0; i < 10; i++) {
		next_x = r * next_x - d;
		cout << next_x << endl;
	}
}