#include<bits/stdc++.h>
using namespace std;
int dp[100001];

int solve(vector<int>&height,int n,int start,int k)
{
	if(start>=n)
	{
		return 0;
	}
	if(dp[start]!=-1)
	return dp[start];
		int res=INT_MAX;
	for(long i=1;i<=k;i++)
	{
	
		if(start+i<=n)
		{
			res=min(abs(height[start+i]-height[start])+solve(height,n,start+i,k),res);
		}
		else
		break;
	 
	}
	return dp[start]=res;
	

}
int main()
{

	memset(dp,-1,sizeof(dp));
	long n,k;
	cin>>n>>k;
	vector<int> height(n+1);
	height[0]=0;
	for(long i=1;i<=n;i++)
	{
		cin>>height[i];
	 } 
	 int start=1;
	cout<<solve(height,n,start,k)<<endl;
		
}