#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

*/

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

	for (int i = 0; i <= k; i++)
		dp[1][i] = (i <= a[1]) ? 1 : 0;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = (mod + dp[i][j - 1] + dp[i - 1][j] - ((j - 1 - a[i]) >= 0 ? dp[i - 1][j - 1 - a[i]] : 0) ) % mod;
		}
	}
	/*for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}*/

	cout << dp[n][k] << endl;
	return 0;
}

