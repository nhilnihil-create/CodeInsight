#include <bits/stdc++.h>

#define int long long

using namespace std;

int dp[1005][1005];

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    const int mod = 1e9+7;

    int h, w;
    cin >> h >> w;
    dp[1][1] = 1;
    char c[h+3][w+3];

    for(int i = 0; i < h+3; i++)
        for(int j = 0; j < w+3; j++)
            c[i][j] = '#';
    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            cin >> c[i][j];

    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++) {
            if(i > 1 || j > 1) {
                if(c[i][j-1] == '.')
                    dp[i][j] += dp[i][j-1];
                if(c[i-1][j] == '.')
                    dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
        }

    cout << dp[h][w];

    return 0;
}
