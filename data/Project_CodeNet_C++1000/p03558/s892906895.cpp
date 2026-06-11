#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+5;
const int inf = 0x3f3f3f3f;
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
int t;
int n,m;
struct node{
	int v,w;
};
struct O{
	int a,b;
	bool operator<(const O &x)const
	{
		return a>x.a;
	}
};
vector<node>G[maxn];
int dis[maxn];
bool vis[maxn];
void Dj(int s)
{
	dis[s] = 0;
	priority_queue<O>q; q.push({0,s});
	while(!q.empty())
	{
		O p = q.top(); q.pop();
		int u = p.b;
		if(vis[u]) continue;
		vis[u] = 1;
		for(node it:G[u])
		{
			int v =it.v,w = it.w; 
			if(dis[u]+w<dis[v] && !vis[v])
			{
				dis[v] = dis[u]+w;
				q.push({dis[v],v});
			}
		}
	 } 
}
int main()
{
//	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<n;++i)
	{
		G[i].push_back({(i+1)%n,1});
		G[i].push_back({(i*10)%n,0});
	 }
	for(int i=0;i<=n;++i) dis[i] = inf;
	Dj(1);  
	printf("%d\n",dis[0]+1);
}
