#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long a[(1<<n)];
	pair<long long,long long> dp[(1<<n)];
	for (int i = 0; i < (1<<n); ++i)
	{
		cin>>a[i];
		dp[i]={a[i],-1000000000000000LL};
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (1<<n); ++j)
		{
			if (j&(1<<i))
			{
				if (dp[j].first<dp[j^(1<<i)].first)
				{
					long long tmp=dp[j].first;
					dp[j].first=dp[j^(1<<i)].first;
					dp[j].second=max(dp[j^(1<<i)].second,tmp);
				}
				else
				{
					dp[j].second=max(dp[j].second,dp[j^(1<<i)].first);
				}
			}
		}
	}
	long long ans=dp[0].first+dp[0].second;
	for (int i = 1; i < (1<<n); ++i)
	{
		ans=max(ans,dp[i].first+dp[i].second);
		cout<<ans<<endl;
	}
	return 0;
}
