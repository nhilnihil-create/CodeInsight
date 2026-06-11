#include <bits/stdc++.h>
#define ll  long long
#define ull unsigned long long  
using namespace std;
#define  inf 1e15+18
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
#define  f1(i,n) for(i=1;i<=n;i++)
#define f0(i,n)  for(i=0;i<n;i++)
#define w(x)   while(x--)
const int maxn=40000;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int  dp[22][(1<<21)+2];
int a[22][22],n;
ll solve(ll id,ll mask)
{
	if(id==n&&mask==(1<<n)-1)
		return 1;
	if(id==n)
		return 0;
	if(dp[id][mask]!=-1)
		return dp[id][mask];
ll ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[id][i]==1&&(mask&(1<<i))==0)
		{
			ans=(ans+solve(id+1,mask|1<<i))%mod;
		}
	}
  dp[id][mask]=ans;

	return ans;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cin>>a[i][j];
	}
	cout<<solve(0,0);
	//cout<<l;
}