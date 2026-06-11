#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const ll INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;
	vector<ll> v(n + 1), pre(n + 1);
	vector< vector<ll> > dp(n + 1, vector<ll>(n + 1, INF));

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		dp[i][i] = 0;
		pre[i] = pre[i - 1] + v[i];
	}
	for (int i = n; i > 0; i--) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k < j; k++) {
				ll temp = dp[i][k] + dp[k + 1][j] + pre[j] - pre[i - 1];
				dp[i][j] = min(temp, dp[i][j]);

			}
		}
	}
	cout << dp[1][n] << '\n';
	return 0;
}