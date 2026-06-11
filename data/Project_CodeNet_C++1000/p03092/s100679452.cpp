#include <bits/stdc++.h>
using namespace std;
int n;
long long AA, BB;
int t[5009];
long long dp[5009][5009]; //from i, limit j
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>AA>>BB;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int i=n; i>=1; i--)
    {
        for(int lim=0; lim<=n; lim++)
        {
            if(t[i]<lim)
            {
                dp[i][lim]=dp[i+1][lim]+BB;
            }
            else
            {
                dp[i][lim]=min(dp[i+1][t[i]], dp[i+1][lim]+AA);
            }
        }
    }
    cout<<dp[1][0]<<endl;
    return 0;
}
