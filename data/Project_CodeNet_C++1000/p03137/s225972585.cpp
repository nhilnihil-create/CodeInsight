#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,m;cin>>n>>m;

    vector<ll> x(m);
    for(int i=0;i<m;i++)cin>>x[i];

    sort(x.begin(),x.end());

    vector<ll> dx(m-1);

    ll ans=0;
    for(int i=1;i<m;i++)
    {
        dx[i-1]=x[i]-x[i-1];
        ans+=dx[i-1];
    }

    sort(dx.begin(),dx.end(),greater<int>());

    for(int i=0;i<min(n-1,m-1);i++)ans-=dx[i];

    cout<<ans<<"\n";

    return 0;
}
