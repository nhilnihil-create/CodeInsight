#include <bits/stdc++.h>

#define int long long

using namespace std;

const int MOD = 1e9 + 7;

int dp[101][100001];

signed main() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            dp[i - 1][j] += dp[i - 1][j - 1];
        }
        for(int j = 0; j <= k; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - a[i] - 1 >= 0) dp[i][j] -= dp[i - 1][j - a[i] - 1];
                dp[i][j] %= MOD;
        }
    }
    cout << dp[n][k];
    return 0;
}
