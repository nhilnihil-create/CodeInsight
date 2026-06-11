#include<bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
const int MAX = 3005;
using namespace std;
int dp[MAX][MAX];
int32_t main()
{
	int n;
	cin>>n;
	string str;
	cin>>str;
	memset(dp, 0, sizeof(dp));
	int pre[n+3];
	memset(pre, 0, sizeof(pre));
	if(str[0] == '<'){
		dp[1][2] = 1;
		pre[2] = 1;
	}
	else{
		dp[1][1] = 1;
		pre[1] = 1;
		pre[2] = 1;
	}

	auto add_self = [&] (int &x, int y)
	{
		x = (x+y)%mod;
		return x;
	};
	for(int i=2;i<n;i++)
	{
		if(str[i-1] == '<')
			dp[i][i+1] = pre[i];

		for(int j=1;j<=i;j++)
		{
			if(str[i-1] == '<')
				dp[i][j] = pre[j-1];
			
			else
				dp[i][j] = (pre[i]-pre[j-1]+mod)%mod;
			
		}
		for(int j=1;j<=n;j++)
			pre[j] = (pre[j-1] + dp[i][j])%mod;
	}
	int ans = 0;
	for(int i=1;i<=n;i++)
		add_self(ans, dp[n-1][i]); 
	
	cout<<ans;
}