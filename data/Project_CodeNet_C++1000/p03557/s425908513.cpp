#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n; cin >> n;
	vector<ll> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ll tmp = b[i];
		ll cnt_a = lower_bound(a.begin(), a.end(), tmp) - a.begin();
		ll cnt_c = c.end() - upper_bound(c.begin(), c.end(), tmp);
		ans += cnt_a * cnt_c;
	}
	cout << ans << endl;
	return 0;
}