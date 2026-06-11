#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#define ll long long
using namespace std;
map<ll,int> us;
ll d[100010];
ll che=0;
int n,cnt=0;
struct node{
	int to,nxt,cap;
}e[200010];
int pos[100010],siz[100010],head[100010],ansa[100010],ansb[100010];
bool cmp(int a,int b){
	return d[a]>d[b];
}
void add(int u,int v){
	e[++cnt].to=v;e[cnt].nxt=head[u];head[u]=cnt;
	e[++cnt].to=u;e[cnt].nxt=head[v];head[v]=cnt;
}
void dfs(int x,int fa,int dep){
	che+=dep;
	int i;
	for(i=head[x];i;i=e[i].nxt){
		if(e[i].to==fa)  continue ;
		dfs(e[i].to,x,dep+1);
	}
}
int main(){
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;++i){
		scanf("%lld",&d[i]);us[d[i]]=i;siz[i]=1;pos[i]=i;
	}
	sort(pos+1,pos+1+n,cmp);
	for(i=1;i<n;++i){
		ll x=d[pos[i]]-(n-siz[pos[i]])+siz[pos[i]];
		if(!us[x] || x>=d[pos[i]]){printf("-1\n");return 0;}
		ansa[i]=us[x];ansb[i]=pos[i];
		add(us[x],pos[i]);
		siz[us[x]]+=siz[pos[i]];
	}
	dfs(pos[n],0,0);
	if(che!=d[pos[n]]){printf("-1\n");return 0;}
	for(i=1;i<n;++i)  printf("%d %d\n",ansa[i],ansb[i]);
	return 0;
}