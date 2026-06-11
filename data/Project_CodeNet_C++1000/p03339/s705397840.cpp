#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
  	string S;
  	cin >> n >> S;
	ll e[n] , w[n];
	e[0] = 0;
	w[0] = 0;
	if( S[0] == 'E' ) e[0] = 1;
	else w[0] = 1;
	for( int i = 1 ; i < n ; i++ ) {
	    if( S[i] == 'E' ) {
            e[i] = e[i - 1] + 1;
  	        w[i] = w[i - 1];
	    } else {
	        e[i] = e[i - 1];
	        w[i] = w[i - 1] + 1;
	    }
	}
    ll ans = e[n - 1] - e[0];
    for( int i = 1 ; i < n ; i++ ) ans = min( ans , e[n - 1] - e[i] + w[i - 1] );
    cout << ans;
}
