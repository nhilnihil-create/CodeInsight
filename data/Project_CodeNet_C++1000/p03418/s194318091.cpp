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
    int n, k; cin >> n >> k;
    ll ans = 0ll;
	if (k==0) {
		ans = n;
		ans *= n;
	}
	else {
		FOR(b, k+1, n+1) {
			int x = 0;
			while (b*x+k<=n) {
				if (b*(x+1)-1 > n) {
					int l = b*x+k;
					int r = min(b*(x+1)-1, n);
					ans += r-l+1;
					// debug(b, x, l, r, ans);
				} else {
					ans += b-k;
					// debug(b, x, b-k, ans);
				}
				x++;
			}
			// debug(b, ans);
		}
	}
    cout << ans << endl;
}