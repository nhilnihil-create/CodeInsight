#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct var{
	int fr,to,nxt;
}edge[101001];
int n,size[101001],cnt,head[101001];
LL d[101001],dis[101001];
map<LL,int>num;
void add(int u,int v)
{
	cnt++;
	edge[cnt].to=v;
	edge[cnt].fr=u;
	edge[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int o,int f)
{
	for(int i=head[o];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==f)continue;
		dis[v]=dis[o]+1;
		dfs(v,o);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		num[d[i]]=i;
		size[i]=1;
	}
	sort(d+1,d+n+1);
	for(int i=n;i>1;i--)
	{
		int u=num[d[i]];
		LL tmp=n-2*size[u],f=d[i]-tmp;
		if(tmp<0)
		{
			printf("-1");
			return 0;
		}
		if(!num.count(f))
		{
			printf("-1");
			return 0;
		}
		int x=num[f];
		add(x,u);
		size[x]+=size[u];
	}
	dfs(num[d[1]],0);
	LL sum=0;
	for(int i=1;i<=n;i++)sum+=dis[i];
	if(sum!=d[1])
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		printf("%d %d\n",edge[i].fr,edge[i].to);
	}
}