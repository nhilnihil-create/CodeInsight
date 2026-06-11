// Problem : D - Snuke Numbers
// Contest : AtCoder Regular Contest 099
// URL : https://atcoder.jp/contests/arc099/tasks/arc099_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using ll = long long;
using namespace std;
#define size(x) (int)x.size()

const int N = 1e6 + 1;

ll binpow(ll n, ll k) {
	ll ans = 1;
	while (k) {
		if (k & 1) {
			ans = ans * n;
		}
		n = n * n;
		k >>= 1;
	}
	return ans;
}

int main() { cin.tie(0)->sync_with_stdio(0);
	vector<ll> ans;
	for (int i = 0; i <= 9; i++) {
		ans.push_back(i);
	}
	for (int i = 19; i < 100; i += 10) {
		ans.push_back(i);
	}
	for (ll i = 2; i <= 10; i++) {
		for (ll j = i * binpow(10, i) - 1; j < i * binpow(10, i + 1); j += binpow(10, i)) {
			ans.push_back(j);
		}
	}
	for (ll i = 11; i <= 15; i++) {
		for (ll j = 11 * binpow(10, i) - 1; j < binpow(10, i + 2); j += binpow(10, i)) {
			ans.push_back(j);
		}
	}
	for (ll i = binpow(10, 14) + binpow(10, 12) - 1; i < binpow(10, 14) + binpow(10, 13); i += 1e12) {
		ans.push_back(i);
	}
	ans.pop_back();
	sort(ans.begin(), ans.end());
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cout << ans[i] << '\n';
	}
}
