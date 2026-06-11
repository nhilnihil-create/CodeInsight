#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define M 66000
#define N 20
using namespace std;
ll n,a[N][N],sc[M],dp[M];
ll dfs(ll s)
{
	if(s<=0)
	{
		return 0;
	}
	if(dp[s]!=-1)
	{
		return dp[s];
	}
	ll i;
	for(i=s;i!=0;i=(i-1)&s)
	{
		dp[s]=max(dp[s],dfs(s-i)+sc[i]);
	}
	return dp[s];
}
int main(){
	ll i,j,k;
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
	}
	memset(dp,-1,sizeof(dp));
	for(i=0;i<(1<<n);i++)
	{
		vector<ll> v;
		sc[i]=0;
		for(j=0;j<n;j++)
		{
			if((i&(1<<j))!=0)
			{
				v.push_back(j);
			}
		}
		for(j=0;j<v.size();j++)
		{
			for(k=j+1;k<v.size();k++)
			{
				sc[i]+=a[v[j]][v[k]];
			}
		}
	}
	cout<<dfs((1<<n)-1)<<endl;
	return 0;
}