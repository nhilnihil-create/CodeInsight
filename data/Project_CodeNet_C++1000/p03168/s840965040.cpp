#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    double p[n + 1], dp[n + 1][n + 1], h = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = dp[i - 1][i - 1] * p[i];
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
        }
    }
    for (int i = n / 2 + 1; i <= n; i++) h += dp[n][i];
    cout << fixed << setprecision(10) << h;
}