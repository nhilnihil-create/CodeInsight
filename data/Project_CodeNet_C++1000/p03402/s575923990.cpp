#include <iostream>
using namespace std;

int main() {
	int A, B; cin >> A >> B; A--, B--;
	cout << "100 100" << endl;
	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (A > 0 && (i % 2 == 0) && (j % 2 == 1)) {
				cout << '.';
				A--;
			}
			else {
				cout << '#';
			}
		}
		cout << endl;
	}

	for (int i = 0; i < 50; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (B > 0 && (i % 2 == 1) && (j % 2 == 1)) {
				cout << '#';
				B--;
			}
			else {
				cout << '.';
			}
		}
		cout << endl;
	}

	return 0;
}