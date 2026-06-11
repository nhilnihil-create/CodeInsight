#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll x; cin >> x;
	ll ans = 0;
	for (ll b = 1; b <= x; b++) {
		for (ll p = 2; p <= 10; p++) {
			ll tmp = pow(b, p);
			if (tmp <= x) ans = max(ans, tmp);
		}
	}

	cout << ans << endl;
	return 0;
}