#include<bits/stdc++.h>
#define M 1000000007
#define pb push_back
#define ll long long int
using namespace std;

int main()
{
	string s,t;
	cin>>s>>t;
	int n = s.length(), m = t.length();
	int dp[n+1][m+1];
	int choice[n+1][m+1];
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				dp[i][j] = 0;
				choice[i][j]=0;
				continue;
			}
			if(s[i-1]==t[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
				choice[i][j] = 3;
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				if(dp[i][j] == dp[i-1][j])
					choice[i][j] = 1;
				else
					choice[i][j] = 2;
			}
		}
	}
	i = n,j = m;
	string ans;
	while(i!=0 && j!=0)
	{
		if(choice[i][j]==3)
		{
			ans.push_back(s[i-1]);
			i--;j--;
		}
		else if(choice[i][j]==1)
			i--;
		else
			j--;
	}
	reverse(ans.begin(),ans.end());
	cout<<ans;
	return 0;

}
