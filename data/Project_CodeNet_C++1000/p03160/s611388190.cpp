
#include<bits/stdc++.h>
using namespace std;
int n,dp[100005];
int main()
{
    cin>>n;
    int ar[n+5];
    for(int i=1;i<=n;i++) cin>>ar[i];
    dp[0]=0;
    dp[1]=0;
    dp[2]=abs(ar[2]-ar[1]);
    for(int i=3;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+abs(ar[i]-ar[i-1]),dp[i-2]+abs(ar[i]-ar[i-2]));
    }
    cout<<dp[n]<<endl;
}
