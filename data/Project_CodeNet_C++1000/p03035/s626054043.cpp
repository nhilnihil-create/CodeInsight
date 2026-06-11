#include <iostream>
using namespace std;

int main() {
	int a; //年齢
	int b; //金額,偶数

	cin >> a >> b;

	if (a >= 13) {
		cout << b << endl;
	}
	else if (6 <= a && a <= 12) {
		cout << (b / 2) << endl;
	}
	else {
		cout << 0 << endl;
	}
}