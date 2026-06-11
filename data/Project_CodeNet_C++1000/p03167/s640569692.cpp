#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007;
using namespace std;
int main() {
	int h,w;
	cin>>h>>w;
	vector<string>grid(h);
	for(int i=0;i<h;i++)
	{
	    cin>>grid[i];
	}
	vector<vector<int>>dp(h,vector<int>(w));
 	dp[0][0]=1;
	for(int i=0;i<h;i++)
	{
	    for(int j=0;j<w;j++)
	    {
	        if(grid[i][j]=='#')
	            continue;
	        if(i==0&&j==0)
	            continue;
	       if(i==0)
                dp[i][j]=dp[i][j-1];
            else if(j==0)
                    dp[i][j]=dp[i-1][j];
            else
                    dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%mod;
	    }
	}
 	cout<<dp[h-1][w-1];
	return 0;
}