//https://atcoder.jp/…/nikkei2019-qual/tasks/nikkei2019_qual_d

#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fastio { ios_base::sync_with_stdio(false), cin.tie(NULL); }
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define for1(i, n) for(int i = 1; i <= (int)(n); i++)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

#ifdef RICARDO
//Header here
	#include "E:\\Code\\dbg.h"
#else
	#define bug(...) "RICARDO MILOS"
#endif


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

//=================================================CODE=================================================//

signed main()
{	
	fastio;
	cout.precision(10);
	cout << fixed;
#ifdef RICARDO		
	freopen("i", "r", stdin);
#endif
	int n, m; cin >> n >> m;
	m += n - 1;
	vvi G(n);
	forn(i, m) {
		int u, v; cin >> u >> v;
		u--, v--;
		G[v].pb(u);
	}

	vi par(n, -1);
	vi h(n, -1);
	function<void(int)> dfs = [&](int u) {
		if((int) G[u].size() == 0) {
			h[u] = 0;
			return;
		}
		for(int v : G[u]) {
			if(h[v] < 0) dfs(v);				
			if(maxi(h[u], h[v] + 1)) par[u] = v;
		}
	};

	forn(i, n) {
		if(par[i] < 0) dfs(i);
		cout << par[i] + 1 << endl;		
	}
#ifdef RICARDO
	cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}