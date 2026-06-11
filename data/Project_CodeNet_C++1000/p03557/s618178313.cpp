#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n), b(n), c(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) cin >> b[i];
	for (ll i = 0; i < n; i++) cin >> c[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	
	ll ans = 0;
	for (int j = 0; j < n; j++) {

		ll a_num, c_num;

		auto Iter_a = lower_bound(a.begin(),a.end(), b[j]);
		auto Iter_c = upper_bound(c.begin(), c.end(), b[j]);

		a_num = Iter_a - a.begin();
		c_num = c.end() - Iter_c;

		ans += a_num * c_num;
	}

	cout << ans << endl;
    return 0;
}