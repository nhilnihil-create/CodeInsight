#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	int c = 0;
	ll tmp = k;
	while (tmp) {
		tmp /= 2;
		c++;
	}
	const int MAX = c;
	ll ans = 0;
	vector<int> cnt(MAX);
	rep(i, n) {
		rep(j, MAX) {
			if (a[i]>>j & 1) cnt[j]++; 
		}
	}
	ll d = 1;
	ll x = 0;
	rep(i, MAX) {
		if(cnt[i] <= n / 2) {
			x += d;
		}
		d *= 2;
	}
	if(x > k) {
		int now = MAX;
		for(int i = MAX; i >= 0; i--) {
			if(x <= k) break;
			if((x>>i & 1) && !(k>>i & 1)) x -= d;
			d /= 2; 
		}
	}
	rep(i, n) ans += a[i]^x;
	cout << ans << endl;
	// rep(i, MAX) cout << cnt[i] << " ";
	// cout << endl;
	return 0;
}