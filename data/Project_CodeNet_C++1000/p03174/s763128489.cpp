#include <bits/stdc++.h>
#define FAST_INPUT ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

const int mod = 1e9 + 7;

void add_self(int& a, int b) {
	a += b;
	if (a > mod) {
		a -= mod;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> can(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> can[i][j];
		}
	}
	vector<int> dp(1 << n); // 2 ^ n
	dp[0] = 1;

	for (int mask = 0; mask < (1 << n) - 1; mask++) {
		int a = __builtin_popcount(mask);
		for (int b = 0; b < n; b++) {
			if (can[a][b] && !(mask & (1 << b))) {
				int m2 = mask ^ (1 << b);
				add_self(dp[m2], dp[mask]);
			}
		}
	}

	cout << dp[(1 << n) - 1] << endl;
}

int main() {
    FAST_INPUT;

    solve();

    return 0;
}
