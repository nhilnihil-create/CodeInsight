#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define mod 1000000007
#define int long long

int path(int src, vector<int> &dp, vector<vector<int>> &a) {
	if (dp[src] != -1)return dp[src];
	int ans = 0;
	for (auto x : a[src]) {
		ans = max(ans, path(x, dp, a));
	}

	return dp[src] = 1 + ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	int i;
	vector<vector<int>> a(n);
	for (i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		a[u].push_back(v);
	}

	vector<int> dp(n);
	fill(dp.begin(), dp.end(), -1);

	int ans = 0;

	for (i = 0; i < n; i++) {
		ans = max(ans, path(i, dp, a));
	}

	cout << ans - 1 << endl;

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