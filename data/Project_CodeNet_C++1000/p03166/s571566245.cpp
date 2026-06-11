#include<bits/stdc++.h>
#define int int64_t

using namespace std;

vector<int> adj[100001];
vector<int> val,vis;

int dfs(int u){
	vis[u] = 1;
	int ans=0;
	for(auto it : adj[u]){
		if(vis[it]) {
			ans = max(ans,1 + val[it]);
			continue;
		}
		ans = max(1+dfs(it),ans);
		
	}
	val[u] = ans;
	return val[u];
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	val.resize(n+1);
	vis.resize(n+1);
	for(int i=1;i<=n;i++) vis[i] = val[i] = 0;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i);
	}
	int mx = INT_MIN;
	for(int i=1;i<=n;i++) mx = max(mx,val[i]);
	
	cout<< mx <<"\n";
}