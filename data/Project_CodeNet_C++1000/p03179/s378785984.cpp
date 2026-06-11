#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll=long long;

main()
{
	int n;
	string s;
	
	cin>>n>>s;
	
	vector<vector<ll>> dp(n+1,vector<ll> (n+1));
	dp[1][1]=1;
	
	for(int len=2;len<=n;len++)
	{
		vector<ll> pre(len);
		for(int i=1;i<len;i++)
		pre[i]=(pre[i-1]+dp[len-1][i])%MOD;
		
		/*for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=len;j++)
			{
				if(i!=j)
				{
					if((i<j)==(s[len-2]=='<'))
					{
						if(i>j)
						dp[len][i]=(dp[len][i]+dp[len-1][j])%MOD;
						else
						dp[len][i]=(dp[len][i]+dp[len-1][j-1])%MOD;
					}
				}
			}
		}*/
		
		if(s[len-2]=='<')
		{
			for(int i=1;i<=len;i++)
			dp[len][i]=(dp[len][i]+pre[len-1]-pre[i-1]+MOD)%MOD;
		}
		else
		{
			for(int i=1;i<=len;i++)
			dp[len][i]=(dp[len][i]+pre[i-1])%MOD;
		}
	}
	
	ll ans=0;
	
	for(int i=1;i<=n;i++)
	{
		ans=(ans+dp[n][i])%MOD;
	}
	
	cout<<ans;
}