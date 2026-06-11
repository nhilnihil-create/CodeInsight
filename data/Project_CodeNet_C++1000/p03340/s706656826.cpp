#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 2e5 + 66;

bool bit (int a, int j) {
	return (1 << j) & a;
}

int cnt[N][22];

void solve () {
	int n;
	cin >> n;
	for (int i = 1, a ; i <= n ; ++ i) {
		cin >> a;
		for (int j = 0 ; j < 22 ; ++ j) {
			cnt[i][j] = cnt[i - 1][j] + bit (a, j);
			// cout << cnt[i][j] << " ";
		}
		// cout << "\n
	}
	ll ans = 0;
	for (int i = 1 ; i <= n ; ++ i) {
		int l = 0, r = i - 1, res = i;
		while (l <= r) {
			int m = (l + r) / 2;
			bool ok = true;
			for (int j = 0 ; j < 22 ; ++ j) {
				ok &= (cnt[i][j] - cnt[m][j] <= 1);
			}
			if (ok) {
				res = m;
				r = m - 1;
			}
			else {
				l = m + 1;
			}
		}
		// cout << i << " " << res << "\n";
		ans += i - res;
	}
	cout << ans;
}

int main () {
	ios;
	// double start_time = clock();
	// cout << fixed << setprecision (10);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
	// cerr << (clock() - start_time) / CLOCKS_PER_SEC;
}
