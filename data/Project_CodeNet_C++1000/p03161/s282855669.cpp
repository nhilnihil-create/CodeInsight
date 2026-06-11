#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
signed main()
{
    SPEED;
    int n,k;
    cin>>n>>k;
    int a[n],dp[n+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dp[1]=abs(a[1]-a[0]);
    for(int i=2;i<n;i++)
    {
        int mn=1e18;
        for(int j=max(0ll,i-k);j<i;j++)
        {
            mn=min(mn,abs(a[j]-a[i])+dp[j]);
        }
        dp[i]=mn;
    }
    cout<<dp[n-1];
}