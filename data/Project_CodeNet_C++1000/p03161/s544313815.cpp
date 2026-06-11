#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF INT_MAX
vector<ll> dp;

ll f(vector<ll> &v,ll n,ll k)
{
    ll i,j;
    dp[0]=0;
    for(i=1;i<=min(n,k);i++)
    {
        for(j=0;j<i;j++)
        {
            dp[i]=min(dp[i],dp[j]+abs(v[j]-v[i]));
        }
    }

    for(;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            dp[i]=min(dp[i],dp[i-j]+abs(v[i]-v[i-j]));
        }
    }

    // for(i=0;i<=n;i++)
    // {
    //     cout<<dp[i]<<" ";
    // }

    // cout<<endl;

    return dp[n];
}

void solve()
{
    ll n,i,ans,k;
    cin>>n>>k;
    dp.resize(n,INF);
    vector<ll> v(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }

    ans=f(v,n-1,k);
    cout<<ans;
}

int main()
{
    solve();
}
