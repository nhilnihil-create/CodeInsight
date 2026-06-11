#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int MOD = 1e9 + 7;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll n;
	cin >> n;
	vector< vector<int> > v((n + 1), vector<int>(n + 1));
	vector<int> dp(1 << n), bit(1 << n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >>  v[i][j];
		}
	}
	dp[0] = 1;
	for (int i = 0; i < (1 << n); i++) {
		bit[i] = bit[i / 2] + (i & 1);
		for (int j = 0; j < n; j++) {
			if (i & (1 << j))	dp[i] +=  dp[i ^ (1 << j)] * v[bit[i]][j + 1];
			if (dp[i] >= MOD) dp[i] -= MOD;
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}
