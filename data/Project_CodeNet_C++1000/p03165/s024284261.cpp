#include<iostream>
using namespace std;
#define ll long long



int main()
{
	ll i,j;
	string a;
	string b;
	cin>>a>>b;
	ll n=a.length();
	ll m=b.length();
	ll dp[n+1][m+1];
	for(i=1;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(i=1;i<=m;i++)
	{
		dp[0][i]=0;
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
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
	ll len=dp[n][m];
	i=n;
	j=m;
	string lcs="";
	while(len>0 && i>=0 && j>=0)
	{
		if(a[i-1]==b[j-1])
		{
			lcs+=a[i-1];
			len--;
			i--;
			j--;
		}
		else
		{
			if(dp[i][j-1]>dp[i-1][j])
			{
				j--;
			}
			else 
			{
				i--;
			}
		}
	}
	for(i=lcs.length()-1;i>=0;i--)
	{
		cout<<lcs[i];
	}
}