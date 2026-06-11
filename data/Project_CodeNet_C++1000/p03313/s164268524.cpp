#pragma GCC optimize("O3")

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 18;

int mx[2][1 << N];

void upd(int m, int x) {
	if (mx[0][m] < x) {
		mx[1][m] = mx[0][m];
		mx[0][m] = x;
	}
	else if (mx[1][m] < x) {
		mx[1][m] = x;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < (1 << n); i++) {
		cin >> mx[0][i];
	}
	for (int i = 0; i < n; i++) {
		for (int m = 0; m < (1 << n); m++) {
			if (m >> i & 1) {
				upd(m, mx[0][m ^ (1 << i)]);
				upd(m, mx[1][m ^ (1 << i)]);
			}
		}
	}
	int cur = 0;
	for (int i = 1; i < (1 << n); i++) {
		cur = max(cur, mx[0][i] + mx[1][i]);
		cout << cur << ' ';
	}
}
