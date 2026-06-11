#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> c(n - 1), s(n - 1), f(n - 1);
	for (ll i = 0; i < n - 1; i++) {
		cin >> c[i] >> s[i] >> f[i];
	}

	for (ll start = 0; start < n - 1; start++) {
		ll ans = 0;
		ans += s[start];
		ans += c[start];
		for (ll i = start + 1; i < n - 1; i++) {			
			ll mod = ans % f[i];
			if (mod != 0) {
				ll diff = f[i] - mod;
				ans += diff;
			}			
			if (!(s[i] <= ans)) ans = s[i];
			ans += c[i];
		}
		cout << ans << endl;
	}
	cout << 0 << endl;
	return 0;
}