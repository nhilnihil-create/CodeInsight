#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 3e3 + 100;

long long int mod = 1e9+7, dp[N][N], par[N];

long long int sum(int l, int r) {
    return (par[r] - par[l] + mod) % mod;
}

int main () {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    dp[1][1]=1;
    for(int i = 2 ; i <= n ; i++ ) {
        char c = s[i-2];
        for(int j = 1 ; j <= n ; j++ ) {
            par[j] = par[j-1] + dp[i-1][j];
            par[j] %= mod;
        }
        for(int  j = 1 ; j <= i ; j++ ) {
            //dp[i][j];
            if(c == '<') {
                dp[i][j] += sum(0, j - 1);
            }
            else {
                dp[i][j] += sum(j-1, i-1);
            }
            dp[i][j] %= mod;
        }
    }
    long long int ans = 0;
    for(int i = 1 ; i <= n ; i++ ) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans;
}
