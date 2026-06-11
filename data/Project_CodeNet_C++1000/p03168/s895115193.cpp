#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7,INF=1e18;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<vector<double> > dp(n+1);
        vector<double> a(n+1);
        dp[0].resize(n+1,0);
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i].resize(n+1,0);
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                dp[i][j+1]+=dp[i-1][j]*a[i];
                dp[i][j]+=dp[i-1][j]*(1-a[i]);
            }
        }
        double ans=0;
        for(int i=n/2+1;i<=n;i++)
        ans+=dp[n][i];
        cout<<setprecision(18)<<fixed<<ans<<"\n";
    }
    return 0;
}