#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
int n,m,ans,low[53],cnt,id[53];
vector<int>g[53];
void dfs(int x,int p){
	id[x]=low[x]=++cnt;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(to==p)continue;
		if(id[to])low[x]=min(low[x],id[to]);
		else dfs(to,x),low[x]=min(low[x],low[to]);
	}
	if(low[x]==id[x]&&p>0)ans++;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=0;
	dfs(1,-1);
	cout<<ans;
}