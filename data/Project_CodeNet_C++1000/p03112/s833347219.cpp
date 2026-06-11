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

const int dir[] = {-1, 0};

int main() {
	int a, b, q; cin >> a >> b >> q;
	vector<ll> sh(a);
	rep(i, a) cin >> sh[i];
	vector<ll> te(b);
	rep(i, b) cin >> te[i];

	rep(i, q) {
		ll ans = LLONG_MAX;
		ll x; cin >> x;
		rep(j, 2) {
			if (j==0) { // shから
				rep(k, 2) {
					ll tot = 0;
					int it = lower_bound(all(sh), x)-sh.begin();
					it += dir[k];
					if (it<0 || it>=a) continue;
					tot += abs(x-sh[it]);
					int it2 = lower_bound(all(te), sh[it])-te.begin();
					ll tmp = LLONG_MAX;
					rep(l, 2) {
						if (l==0) it2--;
						else it2++;
						if (it2<0 || it2>=b) continue;
						chmin(tmp, abs(sh[it]-te[it2]));
					}
					chmin(ans, tot+tmp);
					debug(i,j,k,tot,tmp);
				}
			} else {
				rep(k, 2) {
					ll tot = 0;
					int it = lower_bound(all(te), x)-te.begin();
					it += dir[k];
					if (it<0 || it>=b) continue;
					tot += abs(x-te[it]);
					int it2 = lower_bound(all(sh), te[it])-sh.begin();
					ll tmp = LLONG_MAX;
					rep(l, 2) {
						if (l==0) it2--;
						else it2++;
						if (it2<0 || it2>=a) continue;
						chmin(tmp, abs(te[it]-sh[it2]));
					}
					chmin(ans, tot+tmp);
					debug(i,j,k,tot,tmp);
				}
			}
		}
		cout << ans << endl;
	}
}