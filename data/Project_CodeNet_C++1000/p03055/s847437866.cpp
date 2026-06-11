#include <bits/stdc++.h>
#define N 200005
#define pb push_back
using namespace std;

bool SG[N];
vector<int> g[N];
int len=0,dep[N],p;

void dfs(int x){
	if(dep[x]>len) len=dep[x],p=x;
	for(int i=0;i<g[x].size();++i){
		if(!dep[g[x][i]]){
			dep[g[x][i]]=dep[x]+1;
			dfs(g[x][i]);
		}
	}	
}


int main(){
	int n,i,a,b;
	scanf("%d",&n);
	for(i=1;i<n;++i){
		scanf("%d%d",&a,&b);
		g[a].pb(b),g[b].pb(a);
	}
	SG[1]=1,SG[2]=0,dep[1]=1;
	for(i=3;i<=n;++i){
		if(i%3==0) SG[i]=1;
		else SG[i]=(i%3)&1;
	}
	dfs(1);
	memset(dep,0,sizeof(dep)),dep[p]=1;
	dfs(p);
	if(SG[len]) puts("First");
	else puts("Second");
} 