#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int dp[n + 1][k + 1];
	memset(dp, 0, sizeof(dp));
	int curr = 0;
	for (int i = 0; i <= k; i++) {
		if (i <= a[0])
			curr += 1;
		dp[1][i] = curr;
	}
	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 2; i <= n; i++) {
		curr = 1;
		for (int j = 1; j <= k; j++) {
			int sub = 0;
			if (j - a[i - 1] <= 0) {
				sub = (dp[i - 1][j]) % mod;
			} else {
				sub = (dp[i - 1][j] - dp[i - 1][j - a[i - 1] - 1] + mod) % mod;
			}
			curr = (curr + sub) % mod;
			dp[i][j] = curr;
		}
	}
	cout << (dp[n][k] - ((k - 1 < 0) ? 0 : dp[n][k - 1]) + mod) % mod;
	return 0;
}