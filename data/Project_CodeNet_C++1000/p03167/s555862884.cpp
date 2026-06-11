#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

int path(int x, int y, int m, int n, vector<vector<int>> &dp) {
	if (x == m - 1 && y == n - 1)return 1;
	if (x >= m || y >= n)return 0;
	if (dp[x][y] != -1)return dp[x][y] % mod;
	return dp[x][y] = ((path(x + 1, y, m, n, dp) % mod) + (path(x, y + 1, m, n, dp) % mod)) % mod;
}

void solve() {
	int m, n;
	cin >> m >> n;
	char ch[m][n];
	int i, j;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++)cin >> ch[i][j];
	}
	vector<vector<int>> dp(m, vector<int>(n));
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (ch[i][j] == '.')dp[i][j] = -1;
			else dp[i][j] = 0;
		}
	}
	cout << path(0, 0, m, n, dp) % mod << endl;
	return;
}

int32_t main() {

	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int t = 1;
	// cin >> t;
	while (t--)solve();
	return 0;
}