#include<bits/stdc++.h>
#define rep(i, x) for(ll i = 0; i < x; i++)
#define rep2(i, x) for(ll i = 1; i <= x; i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
const ld pi = 3.141592653589793238;

ll test[1234567];
signed main() {
	ll n, m, k; cin >> n >> m >> k;
	rep(i, k) {
		if (i % 2 == 0) {
			if (n % 2 == 1) { n--; }
			m += n / 2; n /= 2;
		}
		else {
			if (m % 2 == 1) { m--; }
			n += m / 2; m /= 2;
		}
	}
	cout << n << ' ' << m << endl;
	return 0;
}