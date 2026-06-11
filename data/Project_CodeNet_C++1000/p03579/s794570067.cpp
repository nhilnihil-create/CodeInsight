#include<bits/stdc++.h>
using namespace std;
struct var{
	long long to,nxt;
}edge[201001];
long long u,v,c[101001],x1,x2,n,m,head[101001],cnt;
bool flag;
void add(long long u,long long v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(long long o,long long cc)
{
	c[o]=cc;
	if(c[o]==1)x1++;
	else x2++;
	for(int i=head[o];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(c[v])
		{
			if(c[v]==c[o])
			{
				flag=true;
				return ;
			}
		}else
		{
			dfs(v,3-cc);
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs(1,1);
	if(flag)
	{
		printf("%lld",n*(n-1)/2-m);
	}else printf("%lld",x1*x2-m);
}