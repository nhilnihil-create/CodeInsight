#include <bits/stdc++.h>

using namespace std;

#define int 		long long
#define endl 		"\n"
#define mod 		1000000007
#define inf 		1e12
#define IOS 		ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

void addSelf(int& x, int y) {
	x += y;
	if (x > mod)
		x -= mod;
}

void subSelf(int& x, int y) {
	x -= y;
	if (x < 0)
		x += mod;
}

int32_t main() {

	IOS;

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<vector<int>> dp(n + 1, vector<int> (k + 1));

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i <= n; i++)
		dp[i][0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++)
			addSelf(dp[i - 1][j], dp[i - 1][j - 1]);

		for (int j = 1; j <= k; j++) {

			int l = j - min(a[i - 1], j), r = j;

			addSelf(dp[i][j], dp[i - 1][r]);
			if (l > 0)
				subSelf(dp[i][j], dp[i - 1][l - 1]);
		}
	}

	cout << dp[n][k];

	return 0;
}