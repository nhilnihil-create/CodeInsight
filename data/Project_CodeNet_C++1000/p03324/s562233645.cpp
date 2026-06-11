#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll d, n; cin >> d >> n;
	
	ll ans;
	if (d == 0) {
		if (n != 100) ans = n;
		else ans = 101;		
	}
	else {
		ll tmp = 1;
		for (ll i = 0; i < d; i++) {
			tmp *= 100;
		}
		if (n != 100) ans = tmp * n;
		else ans = tmp * 101;
	}

	cout << ans << endl;
	return 0;
}