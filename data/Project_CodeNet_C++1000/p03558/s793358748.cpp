#include<iostream>
#include<queue>
using namespace std;
int k,cnt,inf=0x3f3f3f3f,inqueue[100001],head[100001],dis[100001];
struct bian{
	int to;
	int cost;
    int next;
}edge[200001];
void addedge(int u,int v,int cost)
{
	edge[++cnt].to=v;
	edge[cnt].cost=cost;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int main()
{
	cin>>k;
	for(int i=0;i<=100000;i++)head[i]=-1,dis[i]=inf;
	for(int i=0;i<=k-1;i++)addedge(i,(i+1)%k,1);
	for(int i=0;i<=k-1;i++)addedge(i,10*i%k,0);
	queue <int> q;
	q.push(1);dis[1]=1;inqueue[1]=1;
	while(!q.empty())
	{
		int from=q.front();
		q.pop();
		inqueue[from]=0;
		for(int i=head[from];i!=-1;i=edge[i].next)
		{
			int to=edge[i].to,cost=edge[i].cost;
			if(dis[from]+cost<dis[to])
			{
				dis[to]=dis[from]+cost;
				if(inqueue[to]==0)
				{
					inqueue[to]=1;
					q.push(to);
				}
		    }
		}
	}
	cout<<dis[0]<<endl;
	return 0;
}
