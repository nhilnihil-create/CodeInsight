#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],dp[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),dp[a[i]]=dp[a[i]-1]+1;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    printf("%d\n",n-ans);
}
