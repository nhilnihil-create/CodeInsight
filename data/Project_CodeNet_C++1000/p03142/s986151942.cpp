//### In The Name Of GOD ###

//%% Remember; (((He))) is The (((Accepter))) %%

// GOD IS GREATER ...

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef long double ld ;

//#define int ll
#define pb push_back
#define bp pop_back
#define pf push_front
#define fp pop_front
#define X first
#define Y second
#define IO ios_base::sync_with_stdio(false);
#define sz(a) (int)(a.size())
#define sg(a, b) (a + b - 1) /b

const int MOD = 1000 * 1000 * 1000 + 7;
const int INF = 1 * 1000 * 1000 * 1000 + 200;
const int MLOG = 31;
const int SQ = 400;
const int MAXN = SQ * SQ * 2;

vector < int > out[MAXN], inn[MAXN];
int mn = INF, a[MAXN], par[MAXN], dig[MAXN], mark[MAXN];

void I_am_here(int v) {
	mark[v] = true;
	for(int i : out[v])
		dig[i]--;
}

void dfs(int v = 0) {
	I_am_here(v);
	for(auto i : out[v]) {
		if(!mark[i] && !dig[i])
			par[i] = v, dfs(i);
	}
}

signed main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n + m - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		inn[b].pb(a);
		out[a].pb(b);
		dig[b]++;
	}
	int root = 0;
	for(int i = 0; i < n ; i++)
		if(dig[i] == 0)
			root = i;
	dfs(root);
	par[root] = -1;
	for(int i = 0; i < n; i++)
			cout << par[i] + 1 << endl;
}
