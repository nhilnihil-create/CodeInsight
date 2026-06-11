// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007


int main()
{   
    ll n;cin>>n;
    vector<ll>v;
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            if(i!=n/i)
            {
                v.pb(i);
                v.pb(n/i);
            }
            else
            v.pb(i);
        }
    }
    ll ans=0;
    for(ll i=0;i<v.size();i++)
    {
        if(v[i]!=1 && (n/v[i])==n/(v[i]-1))
        {
            ans+=v[i]-1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}