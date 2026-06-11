#include <bits/stdc++.h>
using namespace std;

/*

a) A stack should be non-decreasing by s+w
    If s[i]+w[i] > s[j]+w[j] , i<j then we can swap i,j 
        and the stack is still vaild

    A pile from top to down w[0] - w[n-1]
    sum[i] = \sum_{i=0}^{i} w[i]

    If a pair of i, j s[i]+w[i] > s[j] + w[j] , i<j
    We need proof after swap i,j sum[i-1]'<=s[j] sum[j-1]'<=s[i]

    We know sum[i] < sum[j], sum[i]<=s[i]+w[i], sum[j]<=s[j]+w[j]
    sum[i-1]<sum[j-1], sum[i-1]<=s[i], sum[j-1]<=s[j]

    If we swap i,j 
    sum[j]' = sum[j] <= s[j]+w[j] < s[i]+w[i]
    sum[j-1]' = sum[j] - w[i] < s[i] + w[i] - w[i] < s[i]
    sum[i-1]'=sum[i-1] < sum[j-1] <= s[j] valid

b) s[i]+w[i] == s[j]+w[j], s[i] should be non-decreasing
	If s[i] > s[j], i<j then we can swap i,j 
        and the stack is still vaild

    we need proof after swap i,j sum[i-1]'<=s[j], sum[j-1]'<=s[i]

    we know sum[i] < sum[j], sum[i]<=s[i]+w[i], sum[j]<=s[j]+w[j]
    sum[i-1]<sum[j-1], sum[i-1]<=s[i], sum[j-1]<=s[j]

    sum[j]'=sum[j] <= s[j] + w[j] = s[i] + w[i]
    sum[j-1]' = sum[j]' - w[i] <= s[i] + w[i] - w[i] = s[i] vaild
    sum[i-1]' = sum[i-1] < sum[j-1] <= s[j] < s[i] vaild

dp[i][j] after i block if sum is j

dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]) (s[i]>=j-w[i])

*/

typedef long long LL;
const int MN=1005;
const int MW=10005;

struct Block
{
	int w,s,v;
	void read()
	{
		scanf("%d%d%d",&w,&s,&v);
	}
	bool operator<(const Block &B) const
	{
		int a=s+w,b=B.s+B.w;
		return a==b?s<B.s:a<b;
	}
}block[MN];

LL dp[MW*2];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		block[i].read();
	sort(block,block+n);
	memset(dp,0x8f,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		int s=block[i].s,w=block[i].w,v=block[i].v;
		for(int j=s+w;j>=w;j--)
			dp[j]=max(dp[j],dp[j-w]+v);
	}
	LL ans=0;
	for(int i=0;i<MW*2;i++)
		ans=max(ans,dp[i]);
	printf("%lld\n",ans);
	return 0;
}