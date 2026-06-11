#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=3e5+5;
ll mod=1e9+7;
ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}

ll g1[N],g2[N],arr[N];
int main()
{
    FIO
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
    {
        g1[i]=__gcd(g1[i-1],arr[i-1]);
    }
     for(int i=n-2;i>=0;i--)
    {
        g2[i]=__gcd(g2[i+1],arr[i+1]);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,__gcd(g1[i],g2[i]));
    cout<<ans;



    return 0;
}