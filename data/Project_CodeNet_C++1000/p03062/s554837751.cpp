#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
ll dp[N][2];//到了第i个位子第i个位子按不按?
//其实可以一维,只是为了方便理解.
int a[N],b[N];

int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)  {cin>>a[i];b[i]=a[i];}
    int pos=n;
    for(int i=1;i<=n;i++)
    {
        a[pos]=b[i];pos--;
    }
   // for(int i=1;i<=n;i++)
   //     for(int j=0;j<2;j++)
   //     dp[i][j]=-2e14;
    dp[2][0]=a[1]+a[2];
    dp[2][1]=-a[1]-a[2];
    for(int i=3;i<=n;i++)
    {
        dp[i][1]=max(dp[i-1][0]-a[i]-2*a[i-1],dp[i-1][1]-a[i]+2*a[i-1]);//这个地方用.
        dp[i][0]=max(dp[i-1][0]+a[i],dp[i-1][1]+a[i]);//这个地方不用.
    }
    //cout<<dp[i][1]<<' '<<dp[i][0]<<endl;
    //cout<<dp[1][0]<<endl;
   // cout<<dp[3][0]<<endl;
    cout<<max(dp[n][0],dp[n][1])<<endl;
    return 0;
}
