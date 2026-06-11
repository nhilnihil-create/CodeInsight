#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define ll long long
#define linf 0x3f3f3f3f3f3f3f3fLL
using namespace std;
const int N = 1e5+5;
const ll mod = 1e9+7;
const ll INF = 1e18;
int head[N];
int ne;
struct edge{
	int to,nt,w;
}e[500004];
queue<int>q;
int dis[100004];
void spfa()
{
	memset(dis,127/3,sizeof(dis));
	dis[1]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nt){
			if( dis[e[i].to]>dis[x]+e[i].w){
				dis[e[i].to]=dis[x]+e[i].w;
				q.push(e[i].to);
			}
		}
	}
}
void add(int u,int v,int w){
	 e[++ne].to = v;e[ne].nt = head[u];
	 e[ne].w=w;
	 head[u]=ne;
}
 
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		add(i,(i+1)%n,1);
		add(i,(i*10)%n,0);
	}
	q.push(1);
	spfa();
	printf("%d\n",dis[0]+1);
 
	return 0;
}