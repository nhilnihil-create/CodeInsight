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

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, m, dis[N];
bool mark[N];
vector<pii> G[N];
bool f = 0;

void DFS(int v){
	mark[v] = 1;
	for (auto u:G[v]){
		if (!mark[u.F]){
			dis[u.F] = dis[v] + u.S;
			DFS(u.F);
		}else{
			if (dis[u.F] != dis[v] + u.S) f = 1;
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		int v, u, w;
		cin >> v >> u >> w;
		G[v].pb({u, w});
		G[u].pb({v, -w}); 
	}
	for (int i = 1; i <= n; i++){
		if (!mark[i]) DFS(i);
	}
	if (f) return cout << "No", 0;
	cout << "Yes";










	return 0;
}
