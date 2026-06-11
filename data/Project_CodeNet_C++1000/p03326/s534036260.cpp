#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

int main() {
	int n, m; cin >> n >> m;
	vector<vector<ll>> cakes(n);
	rep(i, n) {
		ll x, y, z; cin >> x >> y >> z;
		cakes[i] = {x, y, z};
	}

	ll ans = 0;
	rep(bit, 1<<3) {
		vector<vector<ll>> tmp = cakes;
		rep(i, 3) {
			if (bit & 1<<i) {
				rep(j, n) {
					tmp[j][i] *= -1;
				}
			}
		}
		vector<ll> tmp2(n);
		rep(i, n) tmp2[i] = tmp[i][0]+tmp[i][1]+tmp[i][2];
		sort(tmp2.rbegin(), tmp2.rend());
		ll tot = 0;
		rep(i, m) tot += tmp2[i];
		chmax(ans, tot);
	}

	cout << ans << endl;
}