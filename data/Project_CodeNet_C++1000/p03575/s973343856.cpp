#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,vis[500010],depth[500010],low[500010],fa[500010],ans;
vector<int> v[500010];
void dfs(int p,int f){
	fa[p]=f;
	vis[p]=1;
	depth[p]=depth[f]+1;
	low[p]=depth[p];
	for(int i=0;i<v[p].size();i++){
		if(v[p][i]!=f&&!vis[v[p][i]])
			dfs(v[p][i],p);
		if(v[p][i]!=f)
			low[p]=min(low[p],low[v[p][i]]);
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(int i=2;i<=n;i++)
		if(low[i]>=depth[i])
			ans++;
	cout<<ans;
	return 0;
}