#include <iostream>
using namespace std;


int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if (A < B && 2 * C <= A) {
		if (X > Y) {
			cout << 2 * X * C << endl;
		}
		else {
			cout << 2 * Y * C << endl;
		}
	}
	else if (A > B && 2 * C <= B) {
		if (X > Y) {
			cout << 2 * X * C << endl;
		}
		else {
			cout << 2 * Y * C << endl;
		}
	}
	else if (A + B <= C * 2) {
		cout << A * X + B * Y << endl;
	}
	else if(X > Y) {
		if (2 * C > A) {
			cout << 2 * Y * C + (X - Y) * A << endl;
		}
		else {
			cout << 2 * X * C << endl;
		}
	}
	else {
		if (2 * C > B) {
			cout << 2 * X * C + (Y - X) * B << endl;
		}
		else {
			cout << 2 * Y * C << endl;
		}
	}
}