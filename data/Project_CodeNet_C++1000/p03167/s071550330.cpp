# include <bits/stdc++.h>
# define speed ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
# define int long long

using namespace std;

const int N = 1e3 + 7;
const int mod = 1e9 + 7;

int dp[N][N];
string a[N];

int32_t main() {
    speed;
    int n, m;
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) {
        cin >> a[i];
        a[i] = '#' + a[i];
    }
    dp[1][1] = 1;
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            if ( i == 1 && j == 1 || a[i][j] == '#' ) {
                continue;
            }
            if ( i > 1 && a[i - 1][j] == '.' ) {
                dp[i][j] += dp[i - 1][j];
            }
            if ( j > 1 && a[i][j - 1] == '.' ) {
                dp[i][j] += dp[i][j - 1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[n][m];
}
