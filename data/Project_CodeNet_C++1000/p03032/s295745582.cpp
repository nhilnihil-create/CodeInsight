#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define ar array

#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 1e5 + 5;

ll a[N];

void solve () {
	int n, k;
	cin >> n >> k;
	for (int i = 1 ; i <= n ; ++ i) {
		cin >> a[i];
	}
	ll best = 0;
	for (int all = 0 ; all <= k ; ++ all) {
		for (int l = 0 ; l <= all ; ++ l) {
			multiset <ll> s;
			int r = max (l + 1, n + 1 - (all - l));
			ll sum = 0;
			for (int i = 1 ; i <= n ; ++ i) {
				if (i <= l || i >= r) {
					s.insert (a[i]);
					sum += a[i];
				}
			}
			ll left = k - all;
			while (s.size() && *s.begin() < 0 && left) {
				sum -= *s.begin();
				s.erase (s.begin());
				left--;
			}
			best = max (best, sum);
		}
	}
	cout << best;
}

int main () {
	ios;
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
}


