#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const int INF=1e9+7;
ll find(ll aa[],ll nn,ll kk)
{
    vector<ll> dp(nn,INF);
    dp[0]=0;
    for(ll i=0;i<nn;i++)
    {
        for(ll j=i+1;j<=(i+kk);j++)
        {
           if(j<nn) dp[j]=min(dp[j],dp[i]+abs(aa[i]-aa[j]));
           else break;
        }
    }
    return dp[nn-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll nn,kk; cin>>nn>>kk;
    ll aa[nn];
    for(ll i=0;i<nn;i++) cin>>aa[i];
    cout<<find(aa,nn,kk);
}