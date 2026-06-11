#include <bits/stdc++.h>
using namespace std;
#define all(a) begin(a), end(a)
#define csz(a) (int) a.size()
#define pb push_back
#define epb emplace_back
#define mp make_pair
#define load(a, v) fill(begin(a), end(a), v)
#define load_mem(a, v) memset(a, v, sizeof(a));
#define iostream_optimize() ios::sync_with_stdio(false); cin.tie(0);
#define long long long
const long MOD = 1e9+7, LINF = 1e18 + 1e16;
const int INF = 1e9+1;
const double EPS = 1e-10;
const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
const long P1 = 31, P2 = 37, M1 = 1e9+7, M2 = 1e9+9;
 
/* <<<<<<<<<<<<<<<<<<<<<<<<<<<< END TEMPLATE >>>>>>>>>>>>>>>>>>>>>>>>>>> */
const int N = 1e5+1;

int n;
long C, x[N], v[N], pref[N], suff[N], mxsuff[N], mxsuffx[N];
long ans;
int main() {
	iostream_optimize();
	cin >> n >> C;
	for(int i = 0; i < n; i++) cin >> x[i] >> v[i];
	for(int i = 0; i < n; i++) {
		pref[i] = (i ? pref[i-1] : 0) + v[i];
	}
	for(int i = n-1; i >= 0; i--) {
		suff[i] = (i < n-1 ? suff[i+1] : 0) + v[i];
		mxsuff[i] = max((i < n-1 ? mxsuff[i+1] : 0), suff[i] - (C - x[i]));
		mxsuffx[i] = max((i < n-1 ? mxsuffx[i+1] : 0), suff[i] - 2ll * (C - x[i]));
	}
	for(int i = 0; i < n; i++) {
		ans = max(pref[i] - 2*x[i] + (i < n-1 ? mxsuff[i+1] : 0), ans);
		ans = max(pref[i] - x[i] + (i < n-1 ? mxsuffx[i+1] : 0), ans);
	}
	for(int i = 0; i < n; i++) ans = max(suff[i] - (C - x[i]), ans);
	cout << ans;
}
