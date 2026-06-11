#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
 
#define int long long 
#define pb push_back
#define all(s) s.begin(),s.end()
#define pii pair<int,int>
#define fr first
#define sc second
#define bst ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define no cout << "NO" << endl;
#define yes cout << "YES" << endl;

using namespace std;

const int N = 5e5 + 10, mod = 1e9 + 7, inf = 1e18 + 7, logn = 23;
const double pi = acos(-1);

int dp[N], t[4 * N];

int get(int v, int tl, int tr, int l, int r) {
	if(l > tr || tl > r) return 0;
	if(tl == l && tr == r) {
		return t[v];
	}

	int tm = (tl + tr) / 2;
	int gol = get(v + v, tl, tm, l, min(r, tm)),
		gor = get(v + v + 1, tm + 1, tr, max(l, tm + 1), r);

	return max(gol, gor);
}

void update(int v, int tl, int tr, int pos, int val) {
	if(tl == tr) {
		t[v] = val;
	} else {
		int tm = (tl + tr) / 2;
		if(pos <= tm) {
			update(v + v, tl, tm, pos, val);
		} else {
			update(v + v + 1, tm + 1, tr, pos, val);
		}
		t[v] = max(t[v + v], t[v + v + 1]);
	}
}

void solve() {
	//soln
	int n;
	cin >> n;
	vector<int> h(n), a(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dp[h[i]] = a[i];
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		int mx = get(1, 1, n, 1, h[i] - 1);
		dp[h[i]] = max(dp[h[i]], mx + a[i]);
		update(1, 1, n, h[i], dp[h[i]]);
		ans = max(ans, dp[h[i]]);
	}

	cout << ans << endl;
}
main() {
	bst;
	int t = 1;
	//cin >> t;
	while(t--) {
		solve();
	}
}
		