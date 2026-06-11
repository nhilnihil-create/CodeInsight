#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,m;
    cin>>n>>m;

    vector<pair<ll,ll>> a(n);
    for(int i=0;i<n;i++)
    {
        int ia,ib;
        cin>>ia>>ib;
        a[i]=make_pair(ia,ib);
    }

    sort(a.begin(),a.end());

    ll ans=0;

    for(int i=0;m>0;i++)
    {
        ans+=a[i].first*min(a[i].second,m);
        m-=a[i].second;
    }

    cout<<ans<<"\n";

    return 0;
}
