#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

signed main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<ll> x(n), y(n), z(n);
	for(int i = 0; i < n; i++){
		scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);
	}
	ll ans = 0;
	for(int bit = 0; bit < (1 << 3); bit++){
		ll ans1 = 0;
		bool x1 = (bit & (1 << 0)), x2 = (bit & (1 << 1)), x3 = (bit & (1 << 2));
		vector<ll> data(n, 0);
		for(int i = 0; i < n; i++){
			if(x1) data[i] += x[i];
			else data[i] -= x[i];
			if(x2) data[i] += y[i];
			else data[i] -= y[i];
			if(x3) data[i] += z[i];
			else data[i] -= z[i];
		}
		sort(data.begin(), data.end(), greater<ll>());
		for(int i = 0; i < m; i++){
			ans1 += data[i];
		}
		ans = max(ans, ans1);
	}
	cout << ans << endl;
}