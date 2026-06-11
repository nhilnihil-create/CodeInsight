// ABC096C - Half and Half

#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	long long int minT = X * A + Y * B;
//	cout << minT << endl;

	for (long long int i = 0; i <= max(X, Y); i++) {
//		if (2 * i * C + max(X - i, (long long)0) * A + max(Y - i, (long long)0) * B < minT) {
//			cout << 2 * i * C + max(X - i, (long long)0) * A + max(Y - i, (long long)0) * B << endl;
//		}
		minT = min(minT, 2 * i * C + max(X - i, (long long)0) * A + max(Y - i, (long long)0) * B);
	}

	cout << minT << endl;

	return 0;
}
