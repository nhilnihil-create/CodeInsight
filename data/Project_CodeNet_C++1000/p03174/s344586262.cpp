#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define mod 1000000007

ll dp[22][(1<<21)];

ll solve(vector<vector<char> >&mat,ll mask,int i,int n)
{
	if(i>=n)
	{
		if(mask==((1<<n)-1))
		{
			return(1);
		}
		else
		{
			return(0);
		}
	}
	if(dp[i][mask]!=-1)
	{
		return(dp[i][mask]);
	}
	ll j;
	ll ans=0;
	for(j=0;j<n;j++)
	{
		//cout<<((1<<j)&mask)<<" "<<mat[i][j]<<" ";
		if(mat[i][j]=='1' && ((1<<j)&mask)==0)
		{
			//cout<<"yo";
			ans=(ans+solve(mat,((1<<j)|mask),i+1,n))%mod;
		}
	}
	return(dp[i][mask]=ans);
}

int main()
{
	int n;
	cin>>n;
	int i,j;
	memset(dp,-1,sizeof(dp));
	vector<vector<char> >mat(n+1,vector<char>(n+1));
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	cout<<solve(mat,0,0,n);
}