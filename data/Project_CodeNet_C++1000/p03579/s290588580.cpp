#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
long long n,m,vis[maxn],head[maxn],sum[2],e=0;
int pp=0;
struct edge{
	int next,to;
}edge[maxn*2];
void add(int from,int to){
	edge[++e].next=head[from];
	edge[e].to=to;
	head[from]=e;
}
void dfs(int x,int pos){
	vis[x]=pos;
	sum[pos]++;
	pos=(pos==0)?1:0;
	for(int i=head[x];i;i=edge[i].next){
		int to=edge[i].to;
		if(vis[to]!=-1) {
			if(vis[to]!=pos){
				printf("%lld\n",n*(n-1)/2-m);
				pp=1;
				return;
			}
		}
		else dfs(to,pos);
		if(pp) break;
	}
	if(pp) return;
}
int main(){
	int x,y;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		add(x,y);add(y,x);
	}
	memset(vis,-1,sizeof(vis));
	dfs(1,0);
	if(pp) {
		return 0;
	}
	printf("%lld",sum[0]*sum[1]-m);
}