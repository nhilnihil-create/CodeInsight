#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
int main() {
    int h, w;
    cin >> h >> w;
    vector< vector< char > > grid(h, vector< char > (w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) cin >> grid[i][j];
    }
    vector< vector< ll > > dp(h, vector< ll >(w));
    for (int i = 0; i < w; i++) {
        if (grid[0][i] == '.') dp[0][i] = 1;
        else break;
    }
    for (int i = 0; i < h; i++) {
        if (grid[i][0] == '.') dp[i][0] = 1;
        else break;
    }
    for (int i = 1; i < h; i++) {
        for (int j = 1; j < w; j++) {
            if (grid[i][j] == '.') dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            else dp[i][j] = 0;
        }
    }
    
    cout << dp[h - 1][w - 1];
}