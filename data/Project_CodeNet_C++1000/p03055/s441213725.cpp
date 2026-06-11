#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,f[maxn],dep[maxn];
vector<int>g[maxn];
void dfs(int u,int fa){
	for(int i=0;i<g[u].size();i++)
		if(g[u][i]!=fa)
			dep[g[u][i]]=dep[u]+1,dfs(g[u][i],u);
}
int main(){
	f[0]=1;
	f[1]=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		if(f[i-1]&&f[i-2])
			f[i]=0;
		else f[i]=1;
		int x,y;
	for(int i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1,0);
	int t=1;
	for(int i=2;i<=n;i++)
		if(dep[i]>dep[t])
			t=i;
	for(int i=1;i<=n;i++)
		dep[i]=0;
	dfs(t,0);
	t=0;
	for(int i=1;i<=n;i++)
		t=max(t,dep[i]);
	if(f[t])
		puts("First");
	else puts("Second");
}