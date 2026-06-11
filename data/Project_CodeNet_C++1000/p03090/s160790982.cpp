///in the name of Allah the most beneficent the most merciful.
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAX 1e18
#define MIN -1e18
#define MOD 998244353
//#define mod2 20071027
//#define MOD 998244353
#define rep(i,a) for(int i=0;i<a;i++)
#define rep1(i,a) for(int i=1;i<=a;i++)
#define base 139
//#define mod 1000074259
#define base2 31
#define memz(a) memset(a, 0, sizeof(a))
#define memn(a) memset(a, -1, sizeof(a))
#define in1(a) scanf("%lld", &a)
#define in2(a, b) scanf("%lld%lld", &a, &b)
#define TC(c) printf("Case #%lld: ", ++c)
#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const ll N=110, M=1000005;
ll n, a[N];
vector<pair<ll, ll>>edge;
bool ok(ll s)
{
    memz(a);
    edge.clear();
//    cout<<"s "<<s<<endl;
    for(ll i=n;i>=1;i--)
    {
        ll baki=s-a[i],doom=0;
//        cout<<"baki1 "<<baki<<endl;
        if(baki<0) return 0;
        vector<ll>v;
        for(ll j=1;baki>0 && j<i;j++)
        {
            if(baki>=j)
            {
                baki-=j;
                v.pb(j);
            }
            else
            {
                ll d = j-baki;
                doom = d;
                baki=0;
                v.pb(j);
                break;
            }
        }
//        cout<<"baki2 "<<baki<<endl;
        if(baki!=0) return 0;
        for(auto u:v)
        {
            if(u!=doom)
            {
                a[u]+=i;
                a[i]+=u;
                edge.pb({i,u});
            }
        }
    }
    return 1;
}
int main()
{

    in1(n);
    ll l = n, r = (n*(n-1))/2,f=0;
    for(ll s=r; s>=l;s--)
    {
        if(ok(s))
        {
            printf("%lld\n", (ll)edge.size());
            for(auto u:edge)
            {
                printf("%lld %lld\n", u.first, u.second);
            }
            return 0;
        }
    }
    return 0;
}
/*

*/
