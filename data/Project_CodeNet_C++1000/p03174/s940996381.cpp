#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;
	cin >> n;
	int z[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> z[i][j];
		}
	}
	
	vector<long long> dp(1 << n);
	dp[0] = 1;
	for (int i = 0; i < (1 << n) - 1; i++) {
		int m = __builtin_popcount(i);
		for (int w = 0; w < n; w++) {
			if (z[m][w] && !(i&(1 << w))) {
				dp[i|(1 << w)] += dp[i];
				dp[i|(1 << w)] %= mod;
			}
		}
	}
	cout << dp[(1 << n) - 1];
}