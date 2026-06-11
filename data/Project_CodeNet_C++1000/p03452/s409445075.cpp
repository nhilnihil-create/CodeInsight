#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, l, r) for(int i = (l); i < (r); ++i)
#define dd(x) cout << #x << " = " << x << ", "
#define de(x) cout << #x << " = " << x << endl
//-------
const int N = 101010;
int n, m;
int par[N], dis[N];
pii find(int x) {
	if(x == par[x])
		return {x, 0};
	pii res = find(par[x]);
	par[x] = res.fi; dis[x] = dis[x] + res.se;
	return {par[x], dis[x]};
}
int main() {
	scanf("%d%d", &n, &m);
	rep(i, 0, n) par[i] = i;
	bool ans = 1;
	rep(i, 0, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		pii a = find(u), b = find(v);
	//	dd(u), dd(v), de(w);
	//	dd(a.fi), de(a.se);
	//	dd(b.fi), de(b.se);
		if(a.fi == b.fi) {
			ans &= a.se + w == b.se;
		} else {
			if(b.fi == v) {
				par[b.fi] = a.fi;
				dis[b.fi] = a.se + w;
			} else {
				par[a.fi] = b.fi;
				dis[a.fi] = b.se - a.se - w;
			}
		}
	}
	int mn = 0, mx = 0;
	rep(i, 0, n) {
		mn = min(find(i).se, mn);
		mx = max(find(i).se, mx);
	}
	ans &= mx - mn <= 1000000000;
	puts(ans ? "Yes" : "No");
	return 0;
}

