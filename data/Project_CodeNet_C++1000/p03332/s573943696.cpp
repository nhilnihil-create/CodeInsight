#include <iostream>
#include <cstdlib>
#include <cstdio>
#define int long long

const int mod = 998244353 ;
const int N = 1e6 + 5 ;

int g[N] ;

inline int quick (int a , int p) {
	int res = 1 ;
	while ( p ) {
		if ( p & 1 ) res = ( res * a ) % mod ;
		a = ( a * a ) % mod ; p >>= 1 ;
	}
	return res ;
}

inline int inv (int x) { return quick ( x , mod - 2 ) ; }

inline int C (int n , int m) {
	if ( ! m || n == m ) return 1 ;
	if ( n < m ) return 0 ;
	return ( g[n] * inv ( g[m] ) % mod * inv ( g[n-m] ) % mod ) % mod ;
}

int n , a , b , k , ans ;

signed main () {
	scanf ("%lld%lld%lld%lld" , & n , & a , & b , & k ) ;
	if ( k == 0 ) { puts ("1") ; return 0 ; }
	g[0] = g[1] = 1 ;
	for (int i = 2 ; i < N - 1 ; ++ i) g[i] = ( g[i-1] * i ) % mod ;
	if ( b != 0 ) {
		for (int i = 0 ; i <= n ; ++ i) {
			int t = k - i * a ; if ( t < 0 || t % b ) continue ;
			ans = ( ans + C ( n , i ) % mod * C ( n , t / b ) % mod ) % mod ;
		}
	} else for (int i = 0 ; i <= n ; ++ i) if ( i * a == k ) ans = ( ans + C ( n , i ) ) % mod ;
	printf ("%lld\n" , ans % mod ) ;
	return 0 ;
}