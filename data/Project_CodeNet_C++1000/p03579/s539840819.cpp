#include<bits/stdc++.h>
using namespace std;
int n,m,e,res1,res2,head[111111],c[111111],to[222222],link[222222];
bool flag;
void add(int u,int v){to[++e]=v,link[e]=head[u],head[u]=e;}
void dfs(int u){
	if(flag)return;
	for(int i=head[u];i;i=link[i]){
		if(!c[to[i]])c[to[i]]=-c[u],dfs(to[i]);
		else if(c[to[i]]==c[u])flag=1;
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),add(u,v),add(v,u);
	c[1]=1,dfs(1);
	if(flag){printf("%lld",1ll*n*(n-1)/2-m);return 0;}
	for(int i=1;i<=n;i++)c[i]>0?res1++:res2++;
	printf("%lld",1ll*res1*res2-m);
}