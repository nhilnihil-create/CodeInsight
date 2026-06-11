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
const int maxn=100002;
#define  pq priority_queue
#define  ff first
#define  ss second 
#define pb  push_back
#define lb lower_bound
int  dp[maxn][3];
vector<int>v[maxn];
int solve(int id,int par,int col)
{

	ll int ans=0,j=0;
	if(dp[id][col]!=-1)
		return dp[id][col];
	ll ans1=1;
	ll ans2=0;
	if(col==1)
	 ans2=1;
	for(int child:v[id])
	{

		if(child!=par)
		{
			j=1;
			//if(col==1)
			ans1=(ans1*solve(child,id,1))%mod;
			if(col==1)
				ans2=(ans2*solve(child,id,2))%mod;
		}
	}
	
	dp[id][col]=(ans1+ans2)%mod;
return dp[id][col];
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,n;
	cin>>n;
	for(i=0;i<n-1;i++){
		int k,l;
		cin>>k>>l;
		v[k].pb(l);
		v[l].pb(k);
	}

	j=solve(1,-1,1);
	j=j%mod;
	cout<<j;
	//cout<<l;
}