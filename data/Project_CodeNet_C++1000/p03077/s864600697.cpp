#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll p = 5;
	vector<ll> c(p);
	ll ans = 4;
	for (ll i = 0; i < p; i++) {
		cin >> c[i];
	}
	ll minValue = c[min_element(c.begin(), c.end()) - c.begin()];
	ans += (n + minValue - 1) / minValue;
	cout << ans << endl;
	return 0;
}