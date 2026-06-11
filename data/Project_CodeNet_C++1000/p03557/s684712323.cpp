#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<ll> b(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	vector<ll> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());
	ll ans = 0;
	for (int j = 0; j < n; j++) {		
		auto itr_a = lower_bound(a.begin(), a.end(), b[j]);
		ll a_cnt = itr_a - a.begin();
		auto itr_c = upper_bound(c.begin(), c.end(), b[j]);
		ll c_cnt = c.end() - itr_c;
		ans += a_cnt * c_cnt;
	}

	cout << ans << endl;
	return 0;
}