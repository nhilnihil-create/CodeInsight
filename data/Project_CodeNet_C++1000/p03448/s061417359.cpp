#include "bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C, X;
	cin >> A >> B >> C >> X;
	int ans = 0;
	for (int i = 0; i <= A; ++i) {
		for (int j = 0; j <= B; ++j) {
			if ((X - i * 500 - j * 100) >= 0) {
				int n = X - i * 500 - j * 100;
				if (n <= C * 50) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
