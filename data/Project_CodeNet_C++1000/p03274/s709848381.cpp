#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;

	vector<ll> x(n);
	for (int i = 0; i < n; i++) cin >> x[i];

	ll ans = 9223372036854775807LL;
	for (int i = 0; i <= n - k; i++) {
		ll l = x[i];
		ll r = x[i + k - 1];
		ll tmp = min(abs(l) + abs(l - r), abs(l - r) + abs(r));
		ans = min(ans, tmp);
	}

	cout << ans << endl;
	return 0;
}