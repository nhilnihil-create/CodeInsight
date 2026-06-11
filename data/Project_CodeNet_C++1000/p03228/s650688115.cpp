#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	rep(i, K) {
		if (i % 2 == 0) {
			if (A % 2 != 0) {
				A--;
			}
			B += A / 2;
			A /= 2;
		}
		else {
			if (B % 2 != 0) {
				B--;
			}
			A += B / 2;
			B /= 2;
		}
	}
	cout << A << " " << B << endl;
	return 0;
}