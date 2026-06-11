#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,m;cin>>n>>m;

    str s,t;cin>>s>>t;

    ll g=gcd(n,m);
    ll l=lcm(n,m);

    bool ans=true;

    for(int i=0;i<g;i++)
    {
        if(s[i*n/g]!=t[i*m/g]){ans=false;break;}
    }

    cout<<(ans?l:-1)<<"\n";

    return 0;
}
