#include<iostream>

using namespace std;

int main() {
	long long A, B;
	int K;
	cin >> A >> B >> K;

	for (int i = 0; i < K; i++) {
		if (i % 2 == 0) {
			//高橋君ターン
			if (A % 2 == 1) {
				A = A - 1;
			}
			A = A / 2;
			B = B + A;
		}
		else {
			//青木君ターン
			if (B % 2 == 1) {
				B = B - 1;
			}
			B = B / 2;
			A = A + B;
		}
	}

	cout << A << " " << B << endl;
}
