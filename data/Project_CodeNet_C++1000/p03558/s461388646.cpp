#include<bits/stdc++.h>
using namespace std;

const int N=200200,inf=0x3f3f3f3f;

int k;

struct edge
{
	int from,to,w,nextt;
}g[N];
int head[N],cnt=0;
void add(int u,int v,int w)
{
	cnt++;g[cnt].nextt=head[u];head[u]=cnt;g[cnt].to=v;g[cnt].from=u;g[cnt].w=w;
}

int dist[N],inq[N];queue<int> q;
void spfa()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;inq[1]=1;q.push(1);
	while (!q.empty())
	{
		int u=q.front();inq[u]=0;q.pop();
		for (int i=head[u];i;i=g[i].nextt)
		{
			int v=g[i].to,w=g[i].w;
			if (dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if (!inq[v]){inq[v]=1;q.push(v);}
			}
		}
			
	}
}


int main()
{
	cin>>k;
	for (int i=0;i<k;i++) add(i,(i+1)%k,1);
	for (int i=1;i<k;i++) add(i,i*10%k,0);
	spfa();
	cout<<dist[0]+1;
	return 0;
}