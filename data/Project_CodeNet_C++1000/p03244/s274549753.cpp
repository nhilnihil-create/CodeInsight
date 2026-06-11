#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //required
#include <ext/pb_ds/tree_policy.hpp> //required

using namespace __gnu_pbds; 
using namespace std;

template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
typedef long long  ll;
typedef vector<ll> VL;
typedef vector<int> VI;
typedef pair<ll,ll> PLL;
typedef pair<int,int> PII;
#define pb push_back

#define F first
#define S second
#define SZ(a) int((a).size())
#define ALL(a) a.begin(),a.end()
#define fr(i,x,y) for(int i=x;i<y;i++)
#define frr(i,x,y) for(int i=x-1;i>=y;i--)
#define inf 1e18+1
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mod=1000000007;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
ll power(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;}a=a*a;b>>=1;}return ans;}
ll powerm(ll a,ll b){ll ans=1;while(b!=0){if(b&1){ans*=a;ans%=mod;}a=a*a;a%=mod;b>>=1;}return ans%mod;}
// string to integer stoi()
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
const int N=55;
ll fact[N],inv[N];

bool comp(PLL & a,PLL & b)
{
    if(a.S==b.S)
        return a.F<b.F;
    return a.S>b.S;
}
void solve()
{
    ll n;
    cin>>n;
    map<ll,ll> a,b;
    fr(i,0,n)
    {
        ll x;
        cin>>x;
        if(i%2==0)
        {
            a[x]+=1;
        }
        else
        {
            b[x]+=1;
        }
    }
    ll ans=inf,ans2=inf;
    vector<PLL> arr1,arr2;
    for(auto i: a)
    {
        arr1.pb(i);
    }
    for(auto j:b)
    {
        arr2.pb(j);
    }

    sort(ALL(arr1),comp);
    sort(ALL(arr2),comp);
    ll tmp=n/2;
    if(arr1[0].F!=arr2[0].F)
    {
        //cout<<"up\n";
        // cout<<SZ(<<" "<<arr1[0].S<<endl;
        // cout<<tmp<<" "<<arr2[0].S<<endl;
        ans2=(tmp-arr1[0].S)+(tmp-arr2[0].S);
    }
    else
    {
        if(SZ(arr2)==1)
            ans2=min(ans2,(tmp-arr1[0].S)+(tmp));
        else
            ans2=min(ans2,(tmp-arr1[0].S)+(tmp-arr2[1].S));
        if(SZ(arr1)==1)
            ans2=min(ans2,(tmp)+(tmp-arr2[0].S));
        else
            ans2=min(ans2,(tmp-arr1[1].S)+(tmp-arr2[0].S));
           
    }
    cout<<ans2<<endl;
    return;
}
int main()
{
    IOS;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
/* stuff you should look for
        * int overflow, array bounds
        * special cases (n=1?)
        * do smth instead of nothing and stay organized
        * WRITE STUFF DOWN
*/
// BITMASK:
// 1)When some constrall is of the order of 15-20, think of bitmask DP.
// 2)When some constrall is around 40, try out meet in the middle
// 3) See Strings,palindromes,prefix,suffix etc -> KMP,Z algorithm