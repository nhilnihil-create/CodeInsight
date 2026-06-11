#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pii pair<ll,ll>
#define ff first
#define ss second
#define mxx 100005
#define endl "\n"
const ll mod=1e9+7;

int main()
{
    ll n,m;
    cin>>n>>m;

    vector<ll>v[n+5];
    for(int i=0; i<m; i++)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
    }

    ll ans=0,mn=1e9;
    for(int i=1; i<=n; i++)
    {
        if(i==mn)
        {
            ans++;
            mn=1e9;
        }
        if(v[i].size())
        {
            for(auto it:v[i])
                mn=min(mn,it);
        }
    }

    cout<<ans<<endl;

    return 0;
}
