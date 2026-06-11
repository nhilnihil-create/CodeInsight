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
const int N=3e5+5;
ll mod=998244353 ;
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
vector<vector<int>>v;

void back_tarack(vector<int>vv)
{
    if(vv.size()==10)
    {
        v.push_back(vv);
        return;
    }
    vv.push_back(0);
    back_tarack(vv);
    vv.pop_back();

    vv.push_back(1);
    back_tarack(vv);
    vv.pop_back();

}
int n,f[N][10],p[N][11];

int main()
{
    FIO
    cin>>n;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<10; j++)
            cin>>f[i][j];

    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<11; j++)
            cin>>p[i][j];

    }
    ll ans=-1e18;
    for(int mask=1; mask<(1<<10); mask++)
    {
        ll cost=0;
        for(int shop=0; shop<n; shop++)
        {
            int co=0;
            for(int j=0; j<10; j++)
            {
                if(f[shop][j]&&(mask>>j)&1!=0)
                    co++;
            }

            cost+=p[shop][co];
        }
        ans=max(ans,cost);


    }
    cout<<ans;

    return 0;
}
