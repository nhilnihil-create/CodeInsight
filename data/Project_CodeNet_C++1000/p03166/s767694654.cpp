#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long
const int N=1e5+7;

vector<int> g[N];
bool vis[N];
int d[N],dgr[N]; //in-degree

void dfs(int u){
	vis[u]=1;
	for(int v: g[u]){
		if(vis[v]) continue;
		d[v]=max(d[v],d[u]+1);
		dgr[v]--;
		if(!dgr[v]) dfs(v);
	}
}


int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	int n,m;

	cin>>n>>m;
	int u,v;
	for(i=0;i<m;++i){
	    scanf("%d %d",&u,&v);
	    g[u].PB(v);
	    dgr[v]++;
	}
	for(i=1;i<=n;i++){
		if(!vis[i] && !dgr[i]){
			dfs(i);
		}
	}
	int res=0;
	for(i=1;i<=n;++i){
	    res=max(res,d[i]);
	}
	printf("%d\n",res);

		
	return 0;
}