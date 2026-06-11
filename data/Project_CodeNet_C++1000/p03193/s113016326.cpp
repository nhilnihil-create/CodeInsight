#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,h,w;
    cin>>n>>h>>w;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        ll x,y;
        cin>>x>>y;
        if(x>=h && y>=w) ans++;
    }
    cout<<ans;
    return 0;
}
