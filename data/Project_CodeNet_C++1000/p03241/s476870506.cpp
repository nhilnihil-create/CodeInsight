#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> divisor(ll n) {
	vector<ll> res;
	for (ll i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n)
				res.push_back(n / i);
		}
	}

	return res;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<ll> d;
	d = divisor(m);
	ll ans = 1;
	for (int i = 0; i < d.size(); i++) {
		if (m / d[i] >= n) {
			ans = max(ans, d[i]);
		}
	}
	cout << ans << endl;
	return 0;
}