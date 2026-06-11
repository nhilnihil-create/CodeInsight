#include <bits/stdc++.h>

using namespace std;
const int MOD = (int)1e9 + 7;
int add(int a, int b) {
	int c  = a + b;
	if (c >= MOD) c -= MOD;
	return c;
}
int main()
{

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<vector<int>> dp(n + 1, vector<int> (n + 2));

	dp[1][1]  = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 2] == '>') {
			for (int j = i; j >= 1; j--) {
				dp[i][j] = add(dp[i][j + 1], dp[i - 1][j]);
			}
		} else {
			for (int j = 1; j <= i; j++) {
				dp[i][j] = add(dp[i][j - 1], dp[i - 1][j - 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) ans = add(ans, dp[n][i]);
	cout << ans << '\n';
	return 0;
}
