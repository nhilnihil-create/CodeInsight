#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ; 
int n, a[N][N] ;  
signed main()
{
	n = gi() ; int M = 0 ; 
	int m = n + ((n & 1) ^ 1) ;
	rep( i, 1, n ) rep( j, i + 1, n ) if( (i + j) != m ) a[i][j] = 1, ++ M ; 
	cout << M << endl ; 
	rep( i, 1, n ) rep( j, i + 1, n ) {
		if( a[i][j] ) cout << i << " " << j << endl ; 
	}
	return 0 ;
}