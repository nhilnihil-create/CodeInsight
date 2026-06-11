#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int L = a + b;
	int R = c + d;
	if (L == R) {
		cout << "Balanced";
	}
	else if (L > R) {
		cout << "Left";
	}
	else {
		cout << "Right";
	}
}