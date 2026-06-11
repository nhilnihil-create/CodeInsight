#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ri register int
const int N=500005,M=998244353;
int n,u,v,head[200005],Next[400005],adj[400005],k,dp[200005],ans;
void Push(int u,int v)
{
	Next[++k]=head[u];
	head[u]=k;
	adj[k]=v;
}
void dfs(int i,int fa)
{
	int j,mx=0,mxx=0;
	for(j=head[i];j!=0;j=Next[j])
 		if(adj[j]!=fa)
 		{
		 	dfs(adj[j],i);
		 	if(mx<dp[adj[j]]+1)
 			{
 				mxx=max(mxx,mx);
			 	mx=dp[adj[j]]+1;
			}
			else
				mxx=max(mxx,dp[adj[j]]+1);
 		}
 	ans=max(ans,mx+mxx);
 	dp[i]=mx; 
}
int main()
{
	scanf("%d",&n);
	for(ri i=1;i<n;++i)
	{
		scanf("%d %d",&u,&v);
		Push(u,v);
		Push(v,u);
	}
	dfs(1,0);
	++ans;
	if(ans%3==2)
		cout<<"Second";
	else
		cout<<"First";
}
