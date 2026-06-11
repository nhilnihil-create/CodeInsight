#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll a[100010];
ll one[64],zero[64];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,k;cin>>n>>k;

    for(int i=0;i<n;i++) cin>>a[i];

    ll cnt=0;
    for(ll i=k;i!=0;cnt++)i/=2;

    for(int i=0;i<n;i++)
    {
        ll ba=a[i];

        for(int j=0;j<cnt;j++)
        {
            if(ba%2)one[j]++;
            else zero[j]++;

            ba/=2;
        }
    }

    ll x=0;

    for(ll i=cnt-1,j=pow(2,i);i>=0;i--,j/=2)
    {
        if(zero[i]>one[i])
        {
            if(k>=x+j)x+=j;
        }
    }

    ll ans=0;

    for(int i=0;i<n;i++)ans+=(a[i]^x);

    cout<<ans<<"\n";

    return 0;
}
