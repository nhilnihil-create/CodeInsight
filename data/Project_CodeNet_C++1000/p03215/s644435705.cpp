#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 303, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n), cur;
	for(auto &i : a) cin >> i;
	for(int i = 0; i < n; i++)
		for(ll c = 0, j = i; j < n; j++) {
			c += a[j];
			cur.pb(c);
		}
	ll ans = 0;
	for(int z = 60; z--;) {
		vector<ll> f[2];
		for(auto i : cur) f[(i>>z)&1].pb(i);
		if(f[1].size() >= k) cur = f[1], ans += 1ll<<z;
		//cout << f[0].size() << " " << f[1].size() << '\n';
	}
	cout << ans;
	return 0;
}
