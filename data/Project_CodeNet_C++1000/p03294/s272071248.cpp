#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ll a; cin >> a;
		ans += a;
		ans--;
	}

	cout << ans << endl;
	return 0;
}