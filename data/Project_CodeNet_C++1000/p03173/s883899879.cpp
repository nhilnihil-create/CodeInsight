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
ll dp[402][402];
ll a[403];
ll pre[401];
ll get(ll l,ll r)
{
	if(l==0)
		return pre[r];
	return pre[r]-pre[l-1];

}
ll solve(ll l,ll r)
{
	
	if(r-l==0)
	{
		return (0);
	}
	if(dp[l][r]!=-1)
		return dp[l][r];
	ll ans=inf;
	for(int i=l;i<r;i++)
	{
		ans=min(ans,solve(l,i)+solve(i+1,r)+get(l,i)+get(i+1,r));
	}
  dp[l][r]=ans;
  return ans;

}
int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(i==0)
			pre[0]=a[0];
		else
			pre[i]=pre[i-1]+a[i];
	}
	cout<<solve(0,n-1);
	//cout<<l;
}