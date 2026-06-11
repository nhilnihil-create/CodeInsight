//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 100000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;


bool M[N], mark[N];
int n, m, inv[N], par[N], p[N], IN[N], ans[N];
vector<int> G[N], ft, g[N];

int getpar(int v){
	return (par[v] == v ? v : par[v] = getpar(par[v]));
}

void merge(int v, int u){
	v = getpar(v), u = getpar(u);
	if (v == u) return;
	par[v] = u;
}

void DFS(int v, int p = 0){
	M[v] = 1;
	for (auto u:G[v]){
		if (!M[u]) DFS(u, v);
	}
	ft.pb(v);
}

bool cmp(int x, int y){
	return (inv[x] < inv[y]);
}


int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	for (int i = 1; i <= n + m - 1; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u);
		IN[u] ++;
	}
	int root;
	for (int i = 1; i <= n; i++){
		if (IN[i] == 0){
			root = i; 
		}
	}
	DFS(root);
	reverse(all(ft));
	//for (auto u:ft) cout << u << ' ';
	//cout << '\n';
	for (int i = 0; i < ft.size(); i++){
		inv[ft[i]] = i;
	}
	for (int i = 0; i < ft.size(); i++){
		sort(all(G[ft[i]]), cmp);
	}
	for (int i = ft.size() - 1; i >= 0; i--){
		for (auto u:G[ft[i]]){
		//	cout << i << ' ' << u << ' ' << getpar(u) << '\n';
			if (!mark[getpar(u)]){
				//cout << ft[i] << ' ' << u << '\n';
				mark[getpar(u)] = 1;
				ans[u] = ft[i];
			}
		}
		for (auto u:G[ft[i]]){
			mark[getpar(u)] = 0;
			merge(ft[i], u);
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';




	return 0;
}
