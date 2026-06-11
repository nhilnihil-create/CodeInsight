#include <bits/stdc++.h>

#define int long long

using namespace std;

double dp[3000 + 1][3000 + 1];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    cout << fixed << setprecision(10);


    int n;
    cin >> n;
    double p[n + 1];
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = (1 - p[i]) * dp[i - 1][j];
            if(j - 1 >= 0){
                dp[i][j] += p[i] * dp[i - 1][j - 1];
            }
        }
    }

    double ans = 0;

    for(int i = n / 2 + 1; i <= n; i++){
        ans += dp[n][i];
    }

    cout << ans;
    return 0;
}