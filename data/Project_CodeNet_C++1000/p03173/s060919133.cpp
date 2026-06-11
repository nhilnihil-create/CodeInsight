#include<bits/stdc++.h>
using namespace std;
#define ll long long 


ll pref[1000];
ll dp[500][500];

ll solve(ll a[],ll i,ll j)
{
	if(i>=j)
	{
		return(0);
	}
	if(dp[i][j]!=-1)
	{
		return(dp[i][j]);
	}
	ll ans=1000000000000000000;
	ll k;
	for(k=i;k<j;k++)
	{
		ans=min(ans,pref[j]-pref[i-1]+solve(a,i,k)+solve(a,k+1,j));
	}
	return(dp[i][j]=ans);
}
int main()
{
	ll n,i;
	cin>>n;
	ll a[n+1];
	pref[0]=0;
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
		pref[i]=sum;
	}
	memset(dp,-1,sizeof(dp));
	cout<<solve(a,1,n)<<"\n";
}