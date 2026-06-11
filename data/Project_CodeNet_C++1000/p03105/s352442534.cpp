#include<iostream>


using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	if (A * C <= B) {
		cout << C << endl;
	}
	else {
		if (A > B) {
			cout << 0 << endl;
		}
		else {
			cout << B / A << endl;
		}
	}

}
