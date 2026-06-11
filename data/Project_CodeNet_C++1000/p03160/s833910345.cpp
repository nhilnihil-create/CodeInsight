#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
#define INF INT_MAX
vector<ll> dp;

ll f(vector<ll> &v,ll n)
{
    dp[0]=0;
    dp[1]=abs(v[0]-v[1]);

    for(int i=2;i<=n;i++)
    {
        dp[i]=min(dp[i-1]+abs(v[i]-v[i-1]),
                  dp[i-2]+abs(v[i]-v[i-2])
                  );
    }

    return dp[n];
}

void solve()
{
    ll n,i,ans;
    cin>>n;
    dp.resize(n);
    vector<ll> v(n);

    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }

    ans=f(v,n-1);
    cout<<ans;
}

int main()
{
    solve();
}
