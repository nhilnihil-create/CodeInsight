/*
arc 084D
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;

int n;
int ee,h[200005],nex[200005<<1],to[200005<<1],val[200005<<1];
int dis[100005];

void addedge(int x,int y,int z)
{
	nex[++ee] = h[x];
	to[ee] = y;
	val[ee] = z;
	h[x] = ee;
}

void dijkstra()
{
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	pq.push(make_pair(dis[1]=1,1));
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		for(int i=h[x];i!=-1;i=nex[i])
			if(dis[x]+val[i]<dis[to[i]])
			{
				dis[to[i]] = dis[x]+val[i];
				pq.push(make_pair(dis[to[i]],to[i]));
			}
	}
}

int main()
{
	memset(h,-1,sizeof(h));
	memset(dis,INF,sizeof(dis));
	cin>>n;
	addedge(0,10%n,0);
	for(int i=1;i<n;i++)
	{
		addedge(i,(i+1)%n,1);
		addedge(i,(i*10)%n,0);
	}
	dijkstra();
	cout<<dis[0]<<endl;
	
	return 0;
}