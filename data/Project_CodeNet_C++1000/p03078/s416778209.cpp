#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;

int x, y, z, k;
vector<ll> a, b, c;
multiset<ll> sums;

bool valid(ll sum) {
	ll cnt = 0;
	
	for (int i = 0; i < z; ++i) {
		auto it = sums.rbegin();
		while (cnt < k && it != sums.rend() && *it + c[i] >= sum) {
			++cnt, ++it;
		}
	}
	
	return cnt >= k;
}

ll bsearch(ll l, ll r) {
	
	if (l == r) return l;
	if (l + 1 == r) {
		if (valid(r)) return r;
		else return l;
	} else {
		ll m = (l + r) / 2;
		if (valid(m)) return bsearch(m, r);
		else return bsearch(l, m - 1);
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin >> x >> y >> z >> k;
	a.resize(x), b.resize(y), c.resize(z);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	for (auto& i : c) cin >> i;
	
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			sums.insert(a[i] + b[j]);
		}
	}
	
	ll minSum = bsearch(0, 3 * 1e10);
	vector<ll> res;
	
	for (int i = 0; i < z; ++i) {
		auto it = sums.rbegin();
		while (it != sums.rend() && *it + c[i] >= minSum) {
			res.push_back(*it + c[i]);
			++it;
		}
	}
	
	sort(all(res), greater<ll>());
	for (int i = 0; i < k; ++i) cout << res[i] << '\n';
}
