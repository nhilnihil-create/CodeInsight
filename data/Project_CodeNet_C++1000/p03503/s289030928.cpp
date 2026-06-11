#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

void solve_abc_c() {
	ll n;
	ll ans = -INF;

	cin >> n;

	ll f[101][6][3];
	rep(i, n) {
		rep(j, 5) {
			cin >> f[i][j][0] >> f[i][j][1];
		}
	}

	ll p[101][11];
	rep(i, n) {
		rep(j, 11) {
			cin >> p[i][j];
		}
	}

	ll y, g;
	ll v;
	V c(n, 0);
	rep(i, 1 << 10) { // 店の開き方
		if (i == 0) {
			continue;
		}

		rep(k, n) {
			c[k] = 0;
		}
		rep(j, 10) { // 曜日と時間帯
			if (((i >> j) & 1) == 1) {
				y = j / 2;
				g = j % 2;
				rep(k, n) { // 各店
					if (f[k][y][g] == 1) {
						c[k]++;
					}
				}
			}
		}
		v = 0;
		rep(k, n) {
			v += p[k][c[k]];
		}
		ans = max(ans, v);
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_c();

	return 0;
}