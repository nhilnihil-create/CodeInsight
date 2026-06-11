#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int dp[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[2]=abs(a[2]-a[1]);
	for(int i=3;i<=n;i++)
	{
		dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
	}
	printf("%d\n",dp[n]);
}