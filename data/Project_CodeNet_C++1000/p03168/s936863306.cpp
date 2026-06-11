#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	pair<long double, long double> a[3000];
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = 1 - a[i].first;
	}

	vector<vector<long double>> dp(n + 1, vector<long double>(n + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] * a[i - 1].second;
		for (int j = 1; j <= n; j++) {
			dp[i][j] += dp[i - 1][j - 1] * a[i - 1].first;
			dp[i][j] += dp[i - 1][j] * a[i - 1].second;
		}
	}
	long double ans = 0;
	for (int i = n / 2 + 1; i <= n; i++) {
		ans += dp[n][i];
	}
	printf("%.12Lf\n", ans);

	return 0;
}