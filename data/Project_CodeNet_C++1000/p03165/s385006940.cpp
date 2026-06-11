#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	int n=s.length();
	int m=t.length();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j]=0;
			}
			else if(s[i-1]==t[j-1])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	//cout<<dp[n][m]<<endl;
	int i=n,j=m;
	string lcs;
	while(i>0 && j>0)
	{
		if(s[i-1]==t[j-1])
		{
			lcs.push_back(s[i-1]);
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1])
		{
			i--;
		}
		else
		{
			j--;
		}
		//cout<<i<<" "<<j<<endl;
	}
	if(lcs.length()==0)
	{
	    cout<<lcs;
	}
	for(int i=lcs.length()-1;i>=0;i--)
	{
	    cout<<lcs[i];
	}
	return 0;
}