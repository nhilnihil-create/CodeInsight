#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <math.h>
#include <string>
#include <utility>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n , m , c = 0;
    cin >> n;
    ll a[n + 1];
    for( ll i = 1 ; i <= n ; i++ ) {
    	cin >> a[i];
    	a[i] -= i;
	}
    sort( a + 1 , a + n + 1 );
    if( n % 2 ) m = a[n / 2 + 1];
    else m = a[n / 2];
	for( ll i = 1 ; i <= n ; i++ ) {
		c += abs( a[i] - m );
	}
	cout << c;
}
