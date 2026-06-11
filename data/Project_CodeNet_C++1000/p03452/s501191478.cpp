#include<bits/stdc++.h>
using namespace std;
#define next Next
const int N=1e6+5;
#define int long long
int n,m,top,vis[N],dis[N],head[N];
struct node{
	int too,next,zh;
}edge[N];
void add(int a,int b,int c)
{
	edge[++top].too=b;edge[top].zh=c;
	edge[top].next=head[a];head[a]=top;
}
/*char buf[1<<21],*p1=buf,*p2=buf;
inline int gc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}*/
#define gc getchar
inline int read()
{
	int ret=0,f=0;char c=gc();
	while(!isdigit(c)){if(c=='-')f=1;c=gc();}
	while(isdigit(c)){ret=ret*10+c-48;c=gc();}
	if(f)return -ret;return ret;
}
void dfs(int u,int dep)
{
	if(vis[u])
	{
		if(dis[u]!=dep)
		{
			puts("No");
			exit(0);
		}
		return;
	}
	vis[u]=1;
	dis[u]=dep;
	for(int i=head[u];i;i=edge[i].next)
	{
		int v=edge[i].too,w=edge[i].zh;
		dfs(v,dep+w);
	}
}
signed main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
		add(y,x,-z);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i,0);
	puts("Yes");
}