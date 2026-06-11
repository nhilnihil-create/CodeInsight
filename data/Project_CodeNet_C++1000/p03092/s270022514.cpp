#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 5000 + 5 ; 
const int inf = 1e15 + 5 ; 
int n, A, B, p[N], dp[N][N] ; 
signed main()
{
	n = gi(), A = gi(), B = gi() ; 
	rep( i, 1, n ) p[i] = gi() ; 
	memset( dp, 63, sizeof(dp) ), dp[0][0] = 0 ; 
	rep( i, 1, n ) rep( j, 0, i - 1 ) {
		if( p[j] < p[i] ) 
			dp[i][i] = min( dp[i][i], dp[i - 1][j] ),
			dp[i][j] = dp[i - 1][j] + A ; 
		if( p[j] > p[i] ) 
			dp[i][j] = dp[i - 1][j] + B ; 
	}
	int ans = inf ; 
	rep( i, 1, n ) ans = min( ans, dp[n][i] ) ;
	cout << ans << endl ; 
	return 0 ;
}