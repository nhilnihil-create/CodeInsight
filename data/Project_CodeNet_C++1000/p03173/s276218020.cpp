#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, i, j, k;
    cin >> n;
    long long dp[n][n] = {0}, a[n];
    cin >> a[0];
    for(i = 1; i < n; ++i) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for(j = 1; j < n; ++j)
        for(i = 0; i < n-j; ++i) {
            dp[i][i+j] = 1e17;
            for(k = i; k < i+j; ++k)
                dp[i][i+j] = min(dp[i][i+j], dp[i][k] + dp[k+1][i+j] + a[i+j] - (i>0 ? a[i-1] : 0));
        }
    cout << dp[0][n-1];
    return 0;
}