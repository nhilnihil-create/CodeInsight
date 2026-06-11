#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e5+1000;
struct node{
	int v,nxt,c;
}edge[maxn<<2];
int head[maxn],tot;
int vis[maxn],dist[maxn];
int n,m,len=0;
inline void read(int &x){
	x=0;char tmp=getchar();
	while(tmp<'0'||tmp>'9') tmp=getchar();
	while(tmp>='0'&&tmp<='9') x=(x<<1)+(x<<3)+tmp-'0',tmp=getchar();
}
inline void add_edge(int x,int y,int c){
	edge[tot].nxt=head[x];
	edge[tot].v=y;
	edge[tot].c=c;
	head[x]=tot++;
}
inline bool spfa(int x){
	int maxx=0,minn=0;
	dist[x]=0,vis[x]=1;
	queue<int>q;
	q.push(x);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=edge[i].nxt){
			int v=edge[i].v;
			if(!vis[v]){
				dist[v]=dist[u]+edge[i].c;
				maxx=max(dist[v],maxx);
				minn=min(dist[v],minn);
				vis[v]=1;
				q.push(v);
			}
			else if(dist[v]!=dist[u]+edge[i].c)
				return false;
		}
	}
	len=max(len,maxx-minn);
	if(len>1e9) return false;
	return true;
}
int main(){
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int l,r,d;
		read(l),read(r),read(d);
		add_edge(l,r,d);
		add_edge(r,l,-d);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(!spfa(i)){
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}