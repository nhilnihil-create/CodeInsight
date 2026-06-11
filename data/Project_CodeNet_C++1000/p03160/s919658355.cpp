#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<int>height;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    height.push_back(x);
	}
	vector<int>dp(n,INT_MAX);
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
	    for(int j=i+1;j<=i+2;j++)
	    {
	        if(j<n)
	        {
	            dp[j]=min(dp[j],dp[i]+abs(height[i]-height[j]));
	        }
	    }
	}
	cout<<dp[n-1];
	return 0;
}