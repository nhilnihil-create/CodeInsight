#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

int solve2(vector<vector<int>> &dp, vector<vector<int>> &a, int c, int src, int par) {
	if (dp[src][c] != -1)return dp[src][c];
	int ans = 0;
	int c0 = 1, c1 = 1;
	for (auto x : a[src]) {
		if (x != par) {
			c0 = (c0 * (solve2(dp, a, 0, x, src) % mod) ) % mod;
		}
	}
	ans = (ans + c0) % mod;


	if (c == 0) {
		for (auto x : a[src]) {
			if (x != par) {
				c1 = (c1 * (solve2(dp, a, 1, x, src) % mod) ) % mod;
			}
		}
		ans = (ans + c1) % mod;
	}


	return dp[src][c] = ans % mod;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> a(n);
	int i, j;
	for (i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	vector<vector<int>> dp(n, vector<int>(2));
	for (i = 0; i < n; i++) {
		for (j = 0; j < 2; j++)dp[i][j] = -1;
	}
	cout << solve2(dp, a, 0, 0, -1);
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}