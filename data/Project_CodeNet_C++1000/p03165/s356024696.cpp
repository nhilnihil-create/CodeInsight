#include<bits/stdc++.h>
using namespace std;

/*
int LCS(string a,int n1,string b,int n2)
{
	if(n1==0 || n2==0)
	return 0;	
	
	if(a[n1-1]==b[n2-1])
	{
		return 1+LCS(a,n1-1,b,n2-1);
	}
	
	else
	{
		return max(LCS(a,n1-1,b,n2),LCS(a,n1,b,n2-1));
	}
}
*/
string LCS(string a,string b)
{
	int m=a.size();
	int n=b.size();
	
	int dp[m+1][n+1];
	
	for(int i=0;i<=m;i++)
	dp[i][0]=0;
	
	for(int j=0;j<=n;j++)
	dp[0][j]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i-1]==b[j-1])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}

	
	int i=m,j=n;
	string ans;
	while(i>=1 && j>=1)
	{
		if(a[i-1]==b[j-1])
		{
			ans+=a[i-1];
			i--;
			j--;
		}
		else
		{
			if(dp[i-1][j]>dp[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	string a,b;
	cin>>a>>b;
	
	cout<<LCS(a,b);
}
