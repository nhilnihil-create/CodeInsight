#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int dp[n-1][n+1];
	dp[0][0] = 0;
	dp[0][1] = (s[0]=='>');
	dp[0][2] = (s[0]=='<')+dp[0][1];
	int i,j;
	for(i=1;i<n-1;i++)
	{	
		dp[i][0] = 0;
		for(j=1;j<=i+2;j++)
		{
			if(s[i]=='<')
			{
				dp[i][j] = dp[i-1][j-1];
			}
			else
			{	
				dp[i][j] = (dp[i-1][i+1]-dp[i-1][j-1])%M;
				dp[i][j] = (dp[i][j]+M)%M;
			}
			dp[i][j] = (dp[i][j]+dp[i][j-1])%M;
		}
	}
	cout<<dp[n-2][n];
	return 0;

}
