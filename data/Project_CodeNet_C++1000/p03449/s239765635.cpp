#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[2][n], dp[2][n];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    dp[0][0] = a[0][0];
    dp[1][0] = a[1][0] + a[0][0];
    for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + a[0][i];
    for (int i = 1; i < n; i++) dp[1][i] = max(dp[1][i - 1], dp[0][i]) + a[1][i];
    cout << dp[1][n - 1] << endl;
}