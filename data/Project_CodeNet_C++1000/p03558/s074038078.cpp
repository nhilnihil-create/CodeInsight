#include<bits/stdc++.h>
using namespace std;

#define N 100010
#define inf 0x3f3f3f3f
int n,s,t;
int first[N],cnt=0;
int dis[N],vis[N];
struct edge{
	int u,v,w,nxt;
}e[N*20];

inline void add(int u,int v,int w){
	e[++cnt].u=u;e[cnt].v=v;e[cnt].w=w;
	e[cnt].nxt=first[u];first[u]=cnt;
}

void dijkstra(){
	typedef pair<int,int>T;
	priority_queue< T,vector<T>,greater<T> >q;
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(make_pair(0,s));
	while(!q.empty()){
		int u=q.top().second;
		int d=q.top().first;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=first[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(dis[v]>d+e[i].w){
				dis[v]=d+e[i].w;
				q.push(make_pair(dis[v],v));
			}	
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=9;j++)
			add(i,((i-1)*10+j)%n+1,j);
	for(int i=1;i<=9;i++) add(0,i+1,i);
	s=0,t=1;
	dijkstra();
	printf("%d",dis[t]);
	return 0;
}