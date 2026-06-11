#include <iostream>
#include <cstdio>
#include <cctype>
#include <vector>
using namespace std;
const int MAXN=1e5+5;
long long sum,ans;
int n,m,flag,vis[MAXN],cnt[2];
vector<int> v[MAXN];
inline int read()
{
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x;
}
void dfs(int x)
{
	cnt[vis[x]-2]++;
	for(int i=0;i<v[x].size();i++)
	{
		if(vis[v[x][i]])
		{
			if(vis[v[x][i]]==vis[x]) flag=1;
			continue;
		}
		vis[v[x][i]]=vis[x]^1;
		dfs(v[x][i]);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=2,dfs(i),sum=cnt[0]+cnt[1];
			ans+=flag?sum*(sum-1)/2:1ll*cnt[0]*cnt[1];
			sum=cnt[0]=cnt[1]=flag=0;
		}
	printf("%lld\n",ans-m);
	return 0;
}