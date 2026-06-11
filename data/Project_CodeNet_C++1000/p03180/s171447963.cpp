#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	int m = (1 << n);
	vector<ll> cnt(m), dp(m);
	for (int s = 0; s < m; s++)
		for (int i = 0; i < n; i++)
			if (s & (1<<i))
				for (int j = i; j < n; j++)
					if (s & (1<<j))
						cnt[s] += a[i][j];
	for (int s = 0; s < m; s++)
		for (int sub = s; sub > 0; sub = (sub-1) & s)
			dp[s] = max(dp[s], dp[s-sub] + cnt[sub]);
	cout << dp[m-1] << "\n";
	return 0;
}