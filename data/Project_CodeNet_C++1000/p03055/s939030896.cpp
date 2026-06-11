#include <iostream>
using namespace std;
const int MAXN=200005;
struct Edge
{
	int v,next;
}e[MAXN*2];
int h[MAXN],cnt;
void addEdge(int x,int y)
{
	e[++cnt].v=y,e[cnt].next=h[x],h[x]=cnt;
}
int dep[MAXN];
void dfs(int u,int d,int pa)
{
	dep[u]=d;
	for(int i=h[u];i;i=e[i].next)
	{
		if(e[i].v==pa)continue;
		dfs(e[i].v,d+1,u);
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		addEdge(x,y);
		addEdge(y,x);
	} 
	dfs(1,1,-1);
	int cmax,maxi=0;
	for(int i=1;i<=n;i++)
		if(dep[i]>maxi)
			maxi=dep[i],cmax=i;
	dfs(cmax,1,-1);
	maxi=0;
	for(int i=1;i<=n;i++)
		if(dep[i]>maxi)
			maxi=dep[i],cmax=i;
	if(maxi%3==1||maxi%3==0)
		cout<<"First"<<endl;
	else
	 	cout<<"Second"<<endl;
	return 0;
}
