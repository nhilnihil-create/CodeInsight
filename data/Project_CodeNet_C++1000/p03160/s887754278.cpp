#include<bits/stdc++.h>
using namespace std;
int dp[100001];
long solve(vector<long>&height,int n,int start)
{
	if(start>=n)
	{
		return 0;
	}
	if(dp[start]!=-1)
	return dp[start];
	
	return dp[start]=min(abs(height[start+1]-height[start])+solve(height,n,start+1),abs(height[start+2]-height[start])+solve(height,n,start+2));
}
int main()
{
	memset(dp,-1,sizeof(dp));
	long n;
	cin>>n;
	vector<long> height(n+1);
	height[0]=0;
	for(long i=1;i<=n;i++)
	{
		cin>>height[i];
	 } 
	 int start=1;
	cout<<solve(height,n,start)<<endl;
		
}