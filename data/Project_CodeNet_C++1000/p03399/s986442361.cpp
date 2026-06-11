#include<iostream>
using namespace std;
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a >= b&& c >= d) {
		cout << b + d << endl;
	}
	else if (a >= b&& d >= c) {
		cout << b + c << endl;
	}
	else if (b >= a&& c >= d) {
		cout << a + d << endl;
	}
	else cout << a + c << endl;
}