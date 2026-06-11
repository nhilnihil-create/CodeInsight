#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	const long long mod = 1e9 + 7;
	cin >> n;
	vector< vector<int> >a(n, vector<int>(n));
	vector<long long>dp(1 << n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	dp[0] = 1;
	for (int i = 0; i < 1 << n; i++) {
		int num = 0;
		for (int j = 0; j < n; j++)
			if (i >> j & 1)
				num++;
		for (int j = 0; j < n; j++)
			if (i >> j & 1 && a[num - 1][j])
				dp[i] = (dp[i] + dp[i ^ 1 << j]) % mod;
	}
	cout << dp[(1 << n) - 1] << '\n';
	return 0;
}