#include "bits/stdc++.h"
using namespace std;
#define ll long long

int main() {
	ll n, p;
	cin >> n >> p;

	if ( n == 1 ) {
		cout << p << endl;
		return 0;
	}

	ll ans = 1, lim = sqrt(p) + 1;
	for ( ll i = 2; i <= lim; i++ ) {
		ll cnt = 0;
		while ( p % i == 0 ) {
			p /= i;
			cnt++;
			if ( cnt == n ) {
				ans *= i;
				cnt = 0;
			}
		}
	}

	cout << ans << endl;
}
