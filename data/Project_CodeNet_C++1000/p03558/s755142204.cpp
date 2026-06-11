#include<bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;
int k;
int dis[maxn];
struct edge
{
	int v,w;
	edge(int v=0,int w=0):v(v),w(w){}
};
vector<edge>adj[maxn];
bool vis[maxn];
void bfs()
{
	queue<int>q;
	memset(dis,0x3f,sizeof(dis));
	dis[1]=1;vis[1]=true;
	q.push(1);
	int u,v,w;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		vis[u]=0;
		int sz=adj[u].size();
		for(int i=0;i<sz;i++)
		{
			v=adj[u][i].v;
			w=adj[u][i].w;
			if(dis[u]+w<dis[v])
			{
				dis[v]=dis[u]+w;
				if(!vis[v])
				{
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main()
{
	scanf("%d",&k);
	for(int i=1;i<k;i++)
	{
		adj[i].push_back(edge((i+1)%k,1));
		adj[i].push_back(edge(i*10%k,0));
	}
	bfs();
	printf("%d\n",dis[0]);
	return 0;
}