#include<iostream>
#include <vector>
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

vector<vector<long long>>dp;

long long dp_func(vector<vector<int>>&v, int i, int m, int n)
{
	if(i==n)
	return 1;
	
	if(dp[m][i]!=-1)
	return dp[m][i];
	
	long long ans=0;
	for(int j=0;j<n;j++)
	{
		
		if(v[i][j]==1 && (m&(1<<j))==0 )
			ans = (ans + dp_func(v, i+1, m|(1<<j), n) ) % mod;
			
	}
	return dp[m][i] = ans;
}

int main()
{
	
	fast_io;
	int n;
  	//bool x;
	cin>>n;
	vector<vector<int>>v(n,vector<int>(n,0));
	dp.assign((1<<(n+1)),vector<long long >(n,-1));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>v[i][j];
		}
	}
	
	cout<<dp_func(v,0,0,n);
	
}

