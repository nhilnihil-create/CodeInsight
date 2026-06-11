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
    int n , m;
    cin >> n >> m;
	int c = 1;
    for( int i = 1 ; i * i <= m ; i++ ) {
    	if( m % i == 0 ) {
    		if ( m / i >= n ) c = max( c , i );
        	if ( i >= n ) c = max( c , m / i );
		}
    }
    cout << c; 
}
