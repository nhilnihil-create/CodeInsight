#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
#define  point complex<ld>
#define Cp(a,b) ((conj(a)*b).imag())
#define Dp(a,b) ((conj(a)*b).real())
#define dist(a,b) (abs(line(a,b)))
#define angel(a) (atan2(a.Y,a.X)*360/pi)

#define X real()
#define Y imag()

#define line(a,b) (b-a)

#define endl "\n"

#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
const int N=1e5+5;
ll mod=1e9+9;
ll inf=1e18;
ld eps=1e-12;
ld pi=2*2*acos(0);
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

int arr[305];
int co[4];
ld n;
bool vist[305][305][305];
ld dp[305][305][305];

ld solve(int co1,int co2,int co3)
{
    int total=co1+co2+co3;
    if(!total)
        return 0;

    if(vist[co1][co2][co3])
        return dp[co1][co2][co3];
    vist[co1][co2][co3]=1;

    ld co0=n-total,inf=1/(1-(co0/n));
    ld ans=1;

    if(co1)
        ans+=(ld)co1/n*solve(co1-1,co2,co3);

    if(co2)
        ans+=(ld)co2/n*solve(co1+1,co2-1,co3);
    if(co3)
        ans+=(ld)co3/n*solve(co1,co2+1,co3-1);

    return dp[co1][co2][co3]=ans*inf;

}

int main()
{
    FIO
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        co[arr[i]]++;
    }
    cout<<fixed<<setprecision(12)<<solve(co[1],co[2],co[3]);


    return 0;
}
