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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n , m , d = 0;
    cin >> n >> m;
    ll x[n] , y[n] , z[n];
    repll(n) cin >> x[i] >> y[i] >> z[i];
    for( ll i = 0 ; i < n ; i++ ) {
    	ll a[1003] = {};
    	for( ll j = 0 ; j < n ; j++ ) {
    		if( i == 0 ) a[j] = x[j] + y[j] + z[j];
    		else if( i == 1 ) a[j] = x[j] + y[j] - z[j];
    		else if( i == 2 ) a[j] = x[j] - y[j] + z[j];
    		else if( i == 3 ) a[j] = x[j] - y[j] - z[j];
    		else if( i == 4 ) a[j] = -x[j] + y[j] + z[j];
    		else if( i == 5 ) a[j] = -x[j] + y[j] - z[j];
    		else if( i == 6 ) a[j] = -x[j] - y[j] + z[j];
    		else if( i == 7 ) a[j] = -x[j] - y[j] - z[j];
		}
		sort( a , a + n );
		reverse( a , a + n );
		ll c = 0;
		for( ll j = 0 ; j < m ; j++ ) c += a[j];
		d = max( d , c );
	}
	cout << d;
}
