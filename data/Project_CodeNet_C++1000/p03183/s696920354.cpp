#include <bits/stdc++.h>
using namespace std;
int N;
long long dp[100005],ans;
struct Node
{
	int w,s,v;
}pre[1000005];
int temp(Node x,Node y)
{
	return x.s+x.w<y.s+y.w;
}
int main()
{
	scanf("%d",&N);
	for (int i=1;i<=N;i++)
	  scanf("%d%d%d",&pre[i].w,&pre[i].s,&pre[i].v);
    sort(pre+1,pre+N+1,temp);
    for (int i=1;i<=N;i++)
      for (int j=pre[i].w+pre[i].s;j>=pre[i].w;j--)
      {
        dp[j]=max(dp[j],dp[j-pre[i].w]+pre[i].v);
        ans=max(ans,dp[j]);
      }
    printf("%lld",ans);
    return 0;
}