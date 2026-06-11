#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cout.precision(12);

    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j) dp[i][j] = dp[i - 1][j - 1] * p[i - 1];
            dp[i][j] += dp[i - 1][j] * (1 - p[i - 1]);
        }
    }
    double ans = 0;
    for (int i = 0; i <= n; i++) {
        if (i > n / 2)
            ans += dp[n][i];
    }
    cout << ans << endl;
	return 0;
}