#include <bits/stdc++.h>
using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	if (B - A + 1 >= 2 * K) {
		for (int i = A; i < A + K; i++) {
			cout << i << endl;
		}
		for (int j = B - K + 1; j < B + 1; j++) {
			cout << j << endl;
		}
	}
	else {
		for (int k = A; k < B + 1; k++) {
			cout << k << endl;
		}
	}

}