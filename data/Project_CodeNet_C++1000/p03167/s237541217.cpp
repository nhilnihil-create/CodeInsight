#include <bits/stdc++.h>

#define int long long

using namespace std;

signed main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    char a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }
    int dp[n][m];
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i == 0 && j == 0) continue;

            bool up = false, left = false;
            if(j != 0 && a[i][j - 1] == '.'){
                left = true;
            }
            if(i != 0 && a[i - 1][j] == '.'){
                up = true;
            }
            int sum = 0;
            if(up) sum += dp[i - 1][j];
            if(left) sum += dp[i][j - 1];
            dp[i][j] = sum;
            dp[i][j] %= (long long) (1e9 + 7);
        }
    }
    cout << dp[n - 1][m - 1];
    return 0;
}