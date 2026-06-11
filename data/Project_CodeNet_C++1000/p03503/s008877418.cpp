#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll q = 10;
	vector<vector<ll>> f(n, vector<ll>(q));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < q; j++) {
			cin >> f[i][j];
		}
	}
	vector<vector<ll>> p(n, vector<ll>(q + 1));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < q + 1; j++) {
			cin >> p[i][j];
		}
	}

	ll ans = -9223372036854775808LL;
	for (ll bit = 1; bit < (1 << q); ++bit) {
		ll tmpAns = 0;
		for (ll i = 0; i < n; i++) {
			ll cnt = 0;
			for (ll j = 0; j < q; ++j) {
				if (bit & (1 << j) && f[i][j] == 1 ) {
					cnt++;
				}
			}
			tmpAns += p[i][cnt];
		}
		ans = max(ans, tmpAns);
	}
	cout << ans << endl;
	return 0;
}