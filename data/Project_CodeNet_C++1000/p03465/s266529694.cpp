#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
LL sum;
bitset<4000030> dp; 
int main()
{
	scanf("%d",&n);
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		sum+=t;
		dp|=dp<<t;
	}
	for(int i=(sum+1)/2;i<=sum;i++)
	{
		if(dp[i])
		{
			printf("%d\n",i);
			return 0;
		}
	}
}