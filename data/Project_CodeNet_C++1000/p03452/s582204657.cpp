#include<cstdio>
#include<vector>
#include<queue>
struct edge
{
	int to,val;
};
std::vector<edge> a[100005];
int n,m,dis[100005],inq[100005],x[200005],y[200005],v[200005],flag,cnt[100005];
void add(int x,int y,int v){a[x].push_back(edge{y,v});}
void spfa(int s)
{
    int sz=1;
	std::queue<int> q;
    dis[s]=0;q.push(s);inq[s]=1;
    while (!q.empty())
    {
    	int v=q.front();q.pop();inq[v]=0;
    	for (int i=0;i<a[v].size();i++)
    	{
    		int u=a[v][i].to;
    		if (dis[u]==2000000000) ++sz;
    		if (dis[u]!=2000000000&&dis[v]+a[v][i].val!=dis[u])
			{
				flag=1;
				return;
			} 
    		if (dis[v]+a[v][i].val<dis[u])
			{
				dis[u]=dis[v]+a[v][i].val;
				if (!inq[u]) q.push(u),inq[u]=1;
				++cnt[u];
				if (cnt[u]>sz+5)
				{
					flag=1;
				    return;
				}
			}
		}
//		for (int i=1;i<=n;i++) printf("%d ",dis[i]);puts("");
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&v[i]);
		add(x[i],y[i],v[i]),add(y[i],x[i],-v[i]);
	}
	for (int i=1;i<=n;i++) dis[i]=2000000000,inq[i]=0;
	for (int i=1;i<=n;i++)
	{
		if (dis[i]==2000000000) spfa(i);
		if (flag==1) break;
	}
	for (int i=1;i<=m;i++) if (dis[x[i]]+v[i]!=dis[y[i]]) flag=1;
	if (!flag) puts("Yes");
	else puts("No");
	return 0;
}