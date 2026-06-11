#include <bits/stdc++.h>

using namespace std;
#define int long long
using ld = long double;

signed main() {
    int n;
    cin >> n;
    int arr[n+1], pref[n+1];
    int i, j;
    pref[0] = 0;
    for(i=1;i<=n;i++)
        cin >> arr[i];
    for(i=1;i<=n;i++)
        pref[i] = pref[i-1] + arr[i];
    int dp[n+1][n+1];
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j] = 1e18;
    for(i=1;i<=n;i++)
        dp[i][i] = 0;
        
    for(int len = 1;len < n;len++)
    {
        for(i=1;i<=(n-len);i++)
        {
            int j = i + len;
            // merge [i, j]
            for(int k = i; k <= j-1;k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + pref[j] - pref[i-1]);
        }
    }
    cout << dp[1][n] << '\n';
}
