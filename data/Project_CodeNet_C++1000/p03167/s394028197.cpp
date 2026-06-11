
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 1e3 + 5, MOD = 1e9 + 7;

int a[N][N], h, w, dp[N][N];

void solve(){
    cin >> h >> w;
    string a[h] = {string(w, '_')};
    for(int i = 0; i < h; ++i){
        cin >> a[i];
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1; i < h; ++i){
        if(a[i - 1][0] != '#')
        dp[i][0] = 1;
        else
        break;
    }
    for(int j = 1; j < w; ++j){
        if(a[0][j - 1] != '#')
        dp[0][j] = 1;
        else
        break;
    }
    for(int i = 1; i < h; ++i){
        for(int j = 1; j < w; ++j){
            if(a[i - 1][j] != '#' && a[i][j - 1] != '#')
            dp[i][j] = ((dp[i - 1][j] % MOD) + (dp[i][j - 1] % MOD)) % MOD;
            else if(a[i - 1][j] != '#')
            dp[i][j] = dp[i - 1][j];
            else if(a[i][j - 1] != '#')
            dp[i][j] = dp[i][j - 1];
        }
    }
    cout << dp[h - 1][w - 1];
}

int32_t main(){
    IOS;
    int t = 1;
    bool test = 0;
    if(test) cin >> t;
    for(int i = 1; i <= t; ++i)
    solve();
    return 0;
}

/*

  
*/
  