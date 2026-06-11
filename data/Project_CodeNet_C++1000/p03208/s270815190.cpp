#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;
	vector<ll> h(n);
	for (ll i = 0; i < n; i++) {
		cin >> h[i];
	}
	sort(h.begin(), h.end());
	ll ans = 10000000000;
	for (ll i = 0; i < n - k + 1; i++) {
		ll tmp = h[i + k - 1] - h[i];
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}