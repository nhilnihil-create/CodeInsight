#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n, k; cin >> n >> k;
	double ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll tmp = i;
		ll cnt = 0;
		while (tmp < k) {
			tmp *= 2;
			cnt++;
		}
		ll q = n;
		while (cnt--) {
			q *= 2;
		}
		ans += (double)1 / q;
	}
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}