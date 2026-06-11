# include <bits/stdc++.h>
# define int long long
# define fi first
# define se second

using namespace std ;

const int N = 1001, mod = 1e9 + 7 ;
char grid[N][N];
int dp[N][N] ;

int32_t main() {
    //freopen("haybales.in", "r", stdin ) ;
    //freopen("haybales.out", "w", stdout ) ;
    int n, w ;
    cin >> n >> w ;
    for( int i =1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= w;  j ++ ) {
            cin >> grid[i][j] ;
        }
    }
    dp[1][1] = 1 ;
    for( int i = 1 ; i <= n ; i ++ ) {
        for( int j = 1 ; j <= w ; j ++ ) {
            if( grid[i][j] == '#' ) continue ;
            dp[i][j] += dp[i-1][j] + dp[i][j-1] ;
            dp[i][j] %= mod ;
        }
    }
    cout << dp[n][w] ;
}
