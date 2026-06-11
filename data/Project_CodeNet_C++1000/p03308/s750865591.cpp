#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll tmp;
	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if (i == j) continue;
			tmp = abs(a[j] - a[i]);
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}