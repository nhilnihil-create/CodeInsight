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
    ll n , k;
  	cin >> n >> k;
  	ll ans = ( n / k ) * ( n / k ) * ( n / k );
	if ( k % 2 == 1 ) cout << ans;
	else {
		ll c = ( n + ( k / 2 ) ) / k;
		cout << ans + c * c * c;
	}
}
