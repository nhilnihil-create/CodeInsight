#include<bits/stdc++.h>
using namespace std;
#define ll long long 


ll n;
ll dp[(1<<16)+1];
ll sums[(1<<17)-1];

ll compute(ll mask,vector<vector<ll > >&score)
{
	ll sum=0;
	ll i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(mask&(1<<i) && mask&(1<<j))
			{
				sum+=score[i][j];
			}
		}
	}
	return(sum);
}
void precompute(vector<vector<ll > >&score)
{
	ll i;
	for(i=1;i<(1<<n);i++)
	{
		sums[i]=compute(i,score);
	}
}

ll solve(ll mask,vector<vector<ll > >&score)
{
	ll i,j;
	if(mask==0)
	{
		return(0);
	}
	if(dp[mask]!=-1)
	{
		return(dp[mask]);
	}
	ll ans=INT_MIN;
	ll submask;
	for(submask=mask;submask!=0;submask=(submask-1)&mask)
	{
		ans=max(ans,sums[submask]+solve(mask^submask,score));
	}
	return(dp[mask]=ans);
}

int main()
{
	cin>>n;
	ll i,j;
	vector<vector<ll > >score(n,vector<ll>(n));
	memset(dp,-1,sizeof(dp));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>score[i][j];
		}
	}
	precompute(score);
	cout<<solve((1<<n)-1,score);
}