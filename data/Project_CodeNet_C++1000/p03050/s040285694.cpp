#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<ll> divisor(ll n) {
	vector<ll> res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)
				res.push_back(n / i);
		}
	}
	sort(res.begin(), res.end());
	return res;
}
int main() {
	ll n;
	cin >> n;
	auto f = divisor(n);
	ll ans = 0;
	for (ll v : f) {
		ll m = v - 1;
		ll x = n / v;
		if (x < m) {
			ans += m;
		}
	}
	cout << ans << endl;
	return 0;
}