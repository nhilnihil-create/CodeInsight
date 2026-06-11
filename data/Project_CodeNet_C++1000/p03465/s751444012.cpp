#include <bits/stdc++.h>
using namespace std;
const int N=2100;
bitset <N*N> dp;
int n,a[N],sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) sum+=a[i];
	dp[0]=1;
	for (int i=1;i<=n;i++) dp|=(dp<<a[i]);
	for (int i=(sum+1)/2;i<=sum;i++)
	{
		if (dp[i]==1)
		{
			printf("%d\n",i);
			return 0;
		}
	}
}