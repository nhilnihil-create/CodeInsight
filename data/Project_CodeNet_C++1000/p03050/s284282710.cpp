#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> calc(ll n)
{
    vector<ll> ans;
    for(ll i=1;i<=n;i++)
    {
        if(n/i<i)break;
        if(n%i==0)
        {
            ll num=n/i;
            ans.push_back(num);
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;cin>>n;

    vector<ll> v=calc(n);

    ll ans=0;
    for(auto iv:v)
    {
        if(n/iv<iv-1)ans+=iv-1;
    }

    cout<<ans<<"\n";

    return 0;
}
