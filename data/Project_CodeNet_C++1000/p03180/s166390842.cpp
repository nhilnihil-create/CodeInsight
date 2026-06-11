//#pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AC 0
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector< vector<int> > a(n, vector<int>(n));
	vector<long long> dp(1 << n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int i = 0; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			if (1 << j & i)
				for (int k = j + 1; k < n; k++)
					if (1 << k & i)
						dp[i] += a[j][k];
	for (int i = 0; i < 1 << n; i++)
		for (int j = i & (i - 1); j > 0; j = (j - 1) & i)
			dp[i] = max(dp[i], dp[j] + dp[i ^ j]);
	cout << dp[(1 << n) - 1];
	return AC;
}