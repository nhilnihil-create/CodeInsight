#include <bits/stdc++.h>
using namespace std;
long dp[1<<21] = {0};
int main() {
    int n, i, j;
    cin >> n;
    int a[n][n];
    dp[0] = 1;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j)
            cin >> a[i][j];
    for(i = 1; i < (1<<n); ++i)
        for(j = 0, dp[i] = 0; j < n; ++j)
            if(a[__builtin_popcount(i)-1][j] && i&(1<<j))
                dp[i] = (dp[i] + dp[i^(1<<j)]) % 1000000007;
    cout << dp[(1<<n)-1];
    return 0;
}
