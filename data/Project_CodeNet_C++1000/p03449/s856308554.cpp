#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,dp[3][105]={0};
    cin>>n;
    for (int i=1; i<=2; i++)
    {
    	for (int j=1; j<=n; j++)
    	{
	    	scanf("%d",&dp[i][j]);
		dp[i][j]+=max(dp[i-1][j],dp[i][j-1]);
	    }           
    }
	cout<<dp[2][n]<<endl;
	return 0;
} 