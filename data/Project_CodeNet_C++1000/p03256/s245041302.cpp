#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1061109567
#define pb push_back
#define in(s) freopen(s,"r",stdin);
#define out(s) freopen(s,"w",stdout);
#define fi first
#define se second
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
#define fa(i,x) for (auto i:x)
using namespace std;
const int N = 2e5 + 5;
int n, m, deg[N][2], a[N];
vector<int> g[N];
bool rem[N];
signed main() {
	#ifdef aome
	in("aome.inp");	
	#endif
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	fw (i, 0, n) {
		char c; cin >> c;
		if (c == 'A') a[i] = 0;
		else a[i] = 1;
	}
	fw (i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v), g[v].pb(u);
		deg[u][a[v]]++, deg[v][a[u]]++;
	}
	/*
	If there are no cycles, the answer is obviously No
	Else, then it's only possible if every element in the cycle is adjancent to a 'A' and a 'B'
	*/
	queue<int> q;
	fw (i, 0, n) {
		if (!deg[i][0] || !deg[i][1]) rem[i] = 1, q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		fa (v, g[u]) {
			deg[v][a[u]]--;
			if (!deg[v][0] || !deg[v][1]) {
				if (!rem[v]) {
					rem[v] = 1;
					q.push(v);
				}
			}
		}
	}
	fw (i, 0, n) if (!rem[i]) {
		cout << "Yes";
		return 0;
	}
	cout << "No";
	return 0;
}