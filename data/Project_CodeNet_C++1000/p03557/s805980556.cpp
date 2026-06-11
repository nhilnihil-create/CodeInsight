#define rep(i, n) for(ll i = 0; i < n; i++)
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 100000005;


int main() {
	ll n;
	cin >> n;
	vector<ll> a(n), b(n), c(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	rep(i,n) cin >> c[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	ll now_b, num_a, num_c, ans = 0;
	ll idx_a, idx_c;
	rep(i,n) {
		now_b = b[i];
		num_a = 0;
		num_c = 0;

		auto iter_a = lower_bound(a.begin(), a.end(), now_b);
		idx_a = distance(a.begin(), iter_a);
		if (iter_a == a.end()) num_a = n;
		else num_a = idx_a;

		auto iter_c = upper_bound(c.begin(), c.end(), now_b);
		idx_c = distance(c.begin(), iter_c);
		if (iter_c == c.end()) num_c = 0;
		else num_c = n - idx_c;

		ans += num_a * num_c;
	}

	cout << ans << endl;

	return 0;
}
