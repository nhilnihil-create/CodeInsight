#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	cin>>n>>k;
	vector<int>height;
	for(int i=0;i<n;i++)
	{
	    int x;
	    cin>>x;
	    height.push_back(x);
	}
	vector<int>dp(n,INT_MAX);
	dp[0]=0;
// 	cout<<k<<endl;
	for(int i=0;i<n;i++)
	{
	   // cout<<i+1<<"  "<<k+i<<endl;
	    for(int j=i+1;j<=k+i;j++)
	    {
	        if(j<n)
	        {
	            dp[j]=min(dp[j],dp[i]+abs(height[i]-height[j]));
	        }
	    }
	}
// 	for(int i=0;i<n;i++)
// 	    cout<<dp[i]<<"  ";
// 	  cout<<endl;
	cout<<dp[n-1];
	return 0;
}