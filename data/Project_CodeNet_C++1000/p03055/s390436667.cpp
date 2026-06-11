#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=2e5+5;
vector<int>lk[N];
int ans=1,dp[N];
void dfs(int x,int fr)
{
	dp[x]=1;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		chmax(ans,dp[x]+dp[y]);
		chmax(dp[x],dp[y]+1);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;
	cin>>n;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(1,0);
	puts(ans%3==2?"Second":"First");
}