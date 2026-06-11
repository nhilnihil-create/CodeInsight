#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<long long>a(n+1), sum(n+1);
	vector< vector<long long> > dp(n+1, vector<long long>(n+1, 1e18));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][i] = 0;
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i < n; i++)
		for (int j = 1; j + i <= n; j++)
			for (int k = j; k < j + i; k++)
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
	cout << dp[1][n] << '\n';
	return 0;
}