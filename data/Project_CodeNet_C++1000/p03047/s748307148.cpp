#include <bits/stdc++.h>
#define rep( i, n ) for( int ( i ) = 0; ( i ) < ( n ); ( i )++ )
#define repr( i, n ) for( int ( i ) = ( n ); ( i ) >= 0; ( i )-- )
#define FOR( i, m, n ) for( int ( i ) = ( m ); ( i ) < ( n ); ( i )++ )
#define all( x ) ( x ).begin(), ( x ).end()
typedef long long lint;
using namespace std;

int main( void ){
	
	lint n,k,cnt;
	
	cnt = 0;
	
	cin >> n >> k;
	
	rep( i, n ){
		if( i + k <= n ){
			cnt++;
		}
	}
	
	cout << cnt << endl;
	
	return 0;
	
}