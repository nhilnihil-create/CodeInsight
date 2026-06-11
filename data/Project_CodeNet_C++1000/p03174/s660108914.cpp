#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long
#define inf (1LL<<60)

int dp[22][1 << 22];


int solve2(int ladke, int ladki, vector<vector<int>> &a, int n) {
	if (ladke == n && ladki == 0)return 1;
	else if (ladke == n)return 0;
	if (dp[ladke][ladki] != -1)return dp[ladke][ladki];
	int i;
	int ans = 0;
	for (i = 0; i < n; i++) {
		if (a[ladke][i] == 1 && (ladki & (1<<i)) != 0) {
			ans = (ans + solve2(ladke + 1, (ladki ^ (1 << i)), a, n)) % mod;
		}
	}
	return dp[ladke][ladki] = ans;
}

void solve() {
	int n;
	cin >> n;
	memset(dp, -1, sizeof(dp));
	vector<vector<int>> a(n, vector<int>(n));
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)cin >> a[i][j];
	}
	cout << solve2(0, (1 << n) - 1, a, n);
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	solve();
	return 0;
}