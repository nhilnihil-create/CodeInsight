#include<bits/stdc++.h>
#define pb push_back
#define INF 10000009
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

double coins(double p[],vector<vector<double>> &dp,int &n,int count,int i)
{
	if(i>=n && count==0)
	{
		return 1;
	}
	if(i>=n && count>0)
	{
		return 0;
	}
	if(dp[i][count]!=-1)
	{
		return dp[i][count];
	}
	if(n-i<count)
	{
		return dp[i][count]=0;
	}
	if(count>0)
	{
		return dp[i][count]=p[i]*coins(p,dp,n,count-1,i+1)+(1-p[i])*coins(p,dp,n,count,i+1);
	}
	return dp[i][count]=(1-p[i])*coins(p,dp,n,count,i+1);
}

int main()
{
	fastio
	int i,n;
	cin>>n;
	double p[n];
	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}
	vector<vector<double>> dp(n,vector<double>(n+1,-1));
	double ans=0.0;
	for(i=(n+1)/2;i<=n;i++)
	{
		ans+=coins(p,dp,n,i,0);
	}
	cout<<fixed<<setprecision(10)<<ans;
	//printf("%lf",ans);
}