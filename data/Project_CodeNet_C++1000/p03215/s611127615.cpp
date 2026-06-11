#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n + 1, 0);
	for (ll i = 1; i <= n; ++i)cin >> a[i];
	for (ll i = 1; i <= n; ++i)a[i] += a[i - 1];
	vector<ll> now;
	for (ll i = 0; i <= n; ++i) {
		for (ll j = i + 1; j <= n; ++j) {
			now.push_back(a[j] - a[i]);
		}
	}
	for (ll i = 60; i >= 0; --i) {
		vector<ll> tmp;
		for (ll x : now) {
			if (x & (1ll << i)) {
				tmp.push_back(x);
			}
		}
		if (tmp.size() >= k)now = tmp;
	}
	ll ans = now[0];
	for (ll i = 1; i < k; ++i) {
		ans &= now[i];
	}
	cout << ans << endl;
}
