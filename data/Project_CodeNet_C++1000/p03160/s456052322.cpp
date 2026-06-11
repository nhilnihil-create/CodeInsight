#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e5+1;
long long dp[maxn],a[maxn];
int main()
{
    long long n,i;
    cin>>n;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1]=0,dp[2]=abs(a[2]-a[1]);
    for (i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n]<<endl;
}
