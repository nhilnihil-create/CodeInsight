#include<bits/stdc++.h>
#define int int64_t
using namespace std;

int M = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n , k;
    cin >> n >> k;
    int a[n+1];
    for(int i = 1; i <= n; i++) cin >> a[i];
    int dp[n+1][k+1];
    memset(dp , (int)0 , sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= k; i++) dp[0][i] += dp[0][i-1];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            int x = min(j, a[i]) , sum = dp[i-1][j];
            if(j-x > 0) sum = (sum - dp[i-1][j-x-1] + M)%M;
            dp[i][j] = sum;
        }
        for(int j = 1; j <= k; j++) dp[i][j] = (dp[i][j] + dp[i][j-1])%M;
    }
    int ans = dp[n][k];
    if(k > 0) ans = (ans - dp[n][k-1] + M)%M;
    cout << ans << "\n";

    return 0;
}

