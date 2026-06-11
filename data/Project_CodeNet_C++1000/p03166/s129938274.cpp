#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

vector<int>adj[100001];
vector<int>vis(100001);
vector<int>in_degree(100001);
vector<int>dist(100001);

void dfs(int a){
	vis[a]=1;
	for(auto b:adj[a]){
		dist[b]=max(dist[b],dist[a]+1);
		in_degree[b]--;
		if(in_degree[b]==0){
			dfs(b);
		}
	}
}

int32_t main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,x,y,ans=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
    	cin>>x>>y;
    	adj[x].pb(y);
    	in_degree[y]++;
    }
    for(int i=1;i<=n;i++){
    	if(vis[i]!=1 && in_degree[i]==0){
    		dfs(i);
    	}
    }
    for(int i=1;i<=n;i++){
    	ans = max(ans,dist[i]);
    }
    cout<<ans;
    return 0;
}