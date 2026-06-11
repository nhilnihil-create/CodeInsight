#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5, mod = 1e9 + 7;

int solve(int i, int j, vector<int>& a, vector<int>& sum, int dp[401][401]) {
	if (i == j)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];

	int minCost = (1ll << 60);
	int curr_sum = sum[j] - sum[i - 1];

	for (int k = i; k < j; k++) {
		minCost = min(minCost, curr_sum + solve(i, k, a, sum, dp) + solve(k + 1, j, a, sum, dp));
	}
	return dp[i][j] = minCost;
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> a(n + 1), sum(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}

	int dp[401][401];
	memset(dp, -1, sizeof dp);
	cout << solve(1, n, a, sum, dp) << endl;

	return 0;
}