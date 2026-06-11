#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 18;

int mx[2][1 << N];

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		int x;
		cin >> x;
		for (int m = i; m < (1 << n); m = (m + 1) | i) {
			if (mx[0][m] < x) {
				mx[1][m] = mx[0][m];
				mx[0][m] = x;
			}
			else if (mx[1][m] < x) {
				mx[1][m] = x;
			}
		}
	}
	int cur = 0;
	for (int i = 1; i < (1 << n); i++) {
		cur = max(cur, mx[0][i] + mx[1][i]);
		cout << cur << ' ';
	}
}