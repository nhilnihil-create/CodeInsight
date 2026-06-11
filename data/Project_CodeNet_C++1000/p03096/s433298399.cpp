#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+10;
const ll mod = 1e9+7;
int c[N],pos[N];
ll dp[N];
int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		if(i==1)
		{
			dp[i]=1;
			pos[c[i]]=i;
			continue;
		}
		if(c[i]==c[i-1])
		{
			dp[i]=dp[i-1];
			continue;
		}
		dp[i]=(dp[i-1]+dp[pos[c[i]]])%mod;
		pos[c[i]]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}
