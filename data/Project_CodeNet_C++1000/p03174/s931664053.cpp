#include<bits/stdc++.h>
using namespace std ;
 
/*                        [Template]                        */
#define async ios_base::sync_with_stdio(false); cin.tie(NULL);
#define Int long long int
#define let auto
#define of :
#define all(y) y.begin(), y.end()
#define present( x, y ) x.find( y ) != x.end()
#define _matrix(T) vector<vector<T>>
template<class T>
auto matrix( int r, int c, T v ){
	return vector<vector<T>>( r, vector<T>( c, v ) ) ;
}
int mod = (int)1e9 + 7 ;
/************************************************************/
#define popcount __builtin_popcount
bool isSet( int x, int n ){
	return x & ( 1 << n ) ;
}

signed main(){
	int N ; cin >> N ;
	let pos = matrix<int>( N, N, false ) ;
	for( int i = 0 ; i < N ; i++ ){
		for( int j = 0 ; j < N ; j++ ){
			cin >> pos[i][j] ;
		}
	}
	vector<int> dp( 1 << N, 0 ) ;
	dp[0] = 1 ;
	for( int i = 0 ; i < ( 1 << N ) - 1 ; i++ ){
		int a = popcount( i ) ;
		for( int j = 0 ; j < N ; j++ ){
			if( pos[a][j] & !isSet( i, j ) ){
				int m2 = i | ( 1 << j ) ;
				( dp[m2] += dp[i] ) %= mod ;
			}
		}
	}
	cout << dp[ ( 1 << N ) - 1 ] ;
	return 0 ;
}