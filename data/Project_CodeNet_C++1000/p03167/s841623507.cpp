#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	char tem;
	cin >> m >> n;
	ll dp[m][n];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			cin >> tem;
			if (tem == '#')
				dp[i][j] = -1;
		}
	dp[0][0] = 0;
	for (int i = 1; i < n; i++) {
		if (dp[0][i] == -1)
			break;
		dp[0][i] = 1;
	}
	for (int i = 1; i < m; i++) {
		if (dp[i][0] == -1)
			break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (dp[i][j] != -1) {
				if (dp[i - 1][j] != -1)
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
				if (dp[i][j - 1] != -1)
					dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			}
		}
	}
	cout << dp[m - 1][n - 1];


	return 0;
}