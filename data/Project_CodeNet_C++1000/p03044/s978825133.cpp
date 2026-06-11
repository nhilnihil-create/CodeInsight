#include <bits/stdc++.h>
#define newl "\n"
using namespace std;
using lli = long long int;
using vvint = vector <vector <pair <int,int>>>;
const int mod = 1e9 + 7;

const int N = 2e5 + 1;
int n;
vvint adj;
vector <lli> dist;

void dfs(int s,int pred){
	for(auto uu : adj[s]){
		int u = uu.first;
		if(u == pred) continue;
		int d = uu.second;
		dist[u] = dist[s] + d;
		dfs(u,s);
	}
	return;
}

void solve(){
	cin >> n;
	adj = vvint(n);
	dist = vector <lli>(n);
	for(int i = 0;i < n - 1;++i){
		int u,v,w;
		cin >> u >> v >> w;
		--u,--v;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dfs(0,-1);
	for(int i = 0;i < n;++i){
		if(dist[i] % 2 == 0) cout << 1 << newl;
		else cout << 0 << newl;
	}

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout << fixed << setprecision(10);
	#ifdef EXECUTE_LOCALLY
		   freopen("in.txt","r",stdin);
	#endif
	int t = 1;
	//cin >> t;
	while(t--) solve();
	#ifdef EXECUTE_LOCALLY
    	cout << setprecision(3) << "program time: " << (double)clock() / CLOCKS_PER_SEC << newl;
	#endif
	return 0;
}
