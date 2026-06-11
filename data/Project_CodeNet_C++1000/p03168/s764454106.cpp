#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector< vector< double > > dp(n + 1, vector< double > (n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        double prob;
        cin >> prob;
        dp[i][0] = dp[i - 1][0] * (1 - prob);
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j - 1] * prob + dp[i - 1][j] * (1 - prob);
        }
    }
    double ans = 0.0;
    for (int i = 0; i <= n; i++) {
        if (i >= n / 2 + 1) ans += dp[n][i];
    }
    cout.precision(9);
    cout << fixed << ans << "\n";
}