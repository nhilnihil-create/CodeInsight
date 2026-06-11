#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int>g[200001];
int d[200001];
int ans=0,ansd=0;
void dfs(int u,int f){
/*	if(d[u]>ans)ans=d[u],ansd=u;
	for(int i=0;i<g[u].size();i++)
		if(f!=g[u][i]){
			d[g[u][i]]=d[u]+1;
			dfs(g[u][i],u);
		}*/
	for(int i=1;i<=n;i++)d[i]=0;
	queue<int>q;
	q.push(u);
	d[u]=1;
	while(!q.empty()){
		int o=q.front();
		q.pop();
		for(int i=0;i<g[o].size();i++)
			if(!d[g[o][i]]){
				d[g[o][i]]=d[o]+1;
				q.push(g[o][i]);
			}
	}
	ans=0;
	for(int i=1;i<=n;i++)
		if(d[i]>ans)ans=d[i],ansd=i;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	d[1]=1;
	dfs(1,0);
	d[ansd]=1;
	ans=0;
	dfs(ansd,0);
	printf(ans%3!=2?"First\n":"Second\n");
}