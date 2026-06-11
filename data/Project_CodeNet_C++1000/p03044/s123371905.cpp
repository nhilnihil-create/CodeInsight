#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'
vector< pair< int, int > > G[100005];
vector< int > color(100005, -1), vis(100005);

void dfs(int node, int dist, int par = -1){
	//~ cout<<node<<endl;
	if(par == -1){
		color[node] = 1;
	}else{
		if(dist&1){
			color[node] = color[par]^1;
		}else{
			color[node] = color[par];
		}
	}
	for(pair< int, int > i : G[node]){
		if(i.first != par){
			dfs(i.first, i.second, node);
		}
	}
}

void solve(){
	int n; cin>>n;
	for(int i = 1; i<n; i++){
		int u, v, w; cin>>u>>v>>w;
		G[u].push_back({v, w});
		G[v].push_back({u, w});
	}
	dfs(1, 0);
	for(int i = 1; i<=n; i++){
		cout<<color[i]<<endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1; //cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
