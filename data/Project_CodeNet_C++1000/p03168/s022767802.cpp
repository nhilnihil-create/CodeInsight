# include <bits/stdc++.h>
# define fi first
# define se second
# define int long long

using namespace std ;

const int N = 5000 ;
double dp[N][N], vc[N];
int n ;
int32_t main() {
    //freopen("cowsignal.in", "r", stdin ) ;
    //freopen("cowsignal.out", "w", stdout ) ;
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ) {
        cin >> vc[i] ;
	}
	dp[1][1] = 1 - vc[1] ;
	dp[2][1] = vc[1] ;
	for( int i = 1 ; i <= n +1; i ++ ) {
        for( int j = 2 ; j <= n ; j ++ ) {
            //cout << dp[i-1][j-1] * vc[j] << ' ' << dp[i][j-1] * (1 - vc[j] ) << endl;
            dp[i][j] = dp[i-1][j-1] * vc[j] + dp[i][j-1] * ( 1 - vc[j] ) ;
        }
	}
	double ans = 0 ;
	for( int i = n/2+2 ; i <= n+1 ; i ++ ) ans += dp[i][n] ;
	cout << setprecision(9) << ans << endl;
}
