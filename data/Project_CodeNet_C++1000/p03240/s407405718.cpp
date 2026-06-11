#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
using namespace std;
typedef long long ll;
#define rep(n) for( int i = 0 ; i < n ; i++ )
#define REP(n) for( int i = 1 ; i <= n ; i++ )
#define repll(n) for( ll i = 0 ; i < n ; i++ )
#define REPll(n) for( ll i = 1 ; i <= n ; i++ )
#define rep2(n) for( int j = 0 ; j < n ; j++ )
#define REP2(n) for( int j = 1 ; j <= n ; j++ )
#define repll2(n) for( ll j = 0 ; j < n ; j++ )
#define REPll2(n) for( ll j = 1 ; j <= n ; j++ )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int x[102] , y[102] = {} , h[102] = {};
    rep(n) cin >> x[i] >> y[i] >> h[i];
    rep(n) {
	    if( h[i] ) swap( x[0] , x[i] ) , swap( y[0] , y[i] ) , swap( h[0] , h[i] );
	} 
    rep(101) {
    	rep2( 101 ) {
    		int a = abs(i - x[0]) + abs(j - y[0]) + h[0];
            bool w = false;
            for( int k = 1 ; k < n ; k++ ) {
                if ( max( 0 , a - abs( i - x[k] ) - abs( j - y[k] ) ) != h[k] ) w = true;
            }
            if( w == false ) {
                cout << i << ' ' << j << ' ' << a << endl;
                return 0;
            }
		}
	}
}
