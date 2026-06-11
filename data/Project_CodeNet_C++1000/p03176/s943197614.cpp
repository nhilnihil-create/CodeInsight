#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

#define ll long long
#define ld long double
#define pq priority_queue
#define ff first
#define ss second
#define pb push_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define sz(c) ((ll)c.size())
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mod1 998244353
#define mod2 1000000007

#ifdef LL
const ll inf = 1e9;
#else 
const ll inf = 1e18;
#endif

typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

high_resolution_clock::time_point curTime() { return high_resolution_clock::now(); }
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);} //Just add this as a third argument to sort() while sorting an array of pairs; NO NEED FOR ANY ARGUMENTS;
template <typename T>
T fact(T a, T mod){ int res = 1, i; for (i = 2; i <= a; i++){ res *= i; res%=mod;} return res; }
template <typename T>
ll powmod(T a,T b,ll m){ ll ans=1; while(b>0){if(b&1){ans*=a;ans%=m;}a*=a;a%=m;b>>=1;} return ans; }
template <typename T>
ll power(T a, T b){ ll ans=1; while(b>0){if(b&1){ans*=a;}a*=a;b>>=1;}return ans;}
template <typename T>
T max3(T a, T b, T c) { return max((max(a,b), max(b,c))); }
template <typename T>
T min3(T a, T b, T c) { return min((min(a,b), min(b,c))); }
template <typename T>
T mid3(T a, T b, T c) { return a+b+c-max3(a,b,c)-min3(a,b,c); }
template <typename T>
T mid(T a, T b) { return min(a,b)+((max(a,b)-min(a,b))/2); }
template <typename T>
T gcd(T a,T b){ return (b?__gcd(a,b):a); }
template <typename T>
T lcm(T a, T b){ return (a*(b/gcd(a,b))); }
template <typename T>
T cl(T a, T b){ return (a+b-1)/b; }
template <typename T>
T set_bits(T a)
{ return __builtin_popcount(a); }
template <typename T>
T add_self(T& a, T b, T mod){ a+=b; if(a>=mod){ a-=mod; } }
template <typename T>
T to_upper(T s){ transform(s.begin(), s.end(), s.begin(), ::toupper); return s; }
template <typename T>
T to_lower(T s){ transform(s.begin(), s.end(), s.begin(), ::tolower); return s; }

vi t;
ll n;

void build()
{
    for(ll i=n-1;i>0;i--) t[i] = max(t[i<<1], t[i<<1|1]);
}

void update(ll pos, ll val)
{
    for(t[pos+=n]=val;pos>1;pos>>=1) t[pos>>1] = max(t[pos], t[pos^1]);
}

ll ask(ll l, ll r)
{
    ll res=0;

    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1) res=max(t[l++], res);
        if(r&1) res=max(res, t[--r]);
    }

    return res;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    auto startTime = curTime();

    cin>>n;
    t.resize(2*n, 0);
    ll a[n],h[n];
    for(ll i=0;i<n;i++)
    {
        cin>>h[i];
        h[i]--;
    }
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
    }

    vi dp(n,0);
    for(ll i=0;i<n;i++)
    {
        dp[i] = max(dp[i], ask(0,h[i]) + a[i]);
        update(h[i], dp[i]);
    }

    ll mx=0;
    for(ll i=0;i<n;i++) mx=max(mx, dp[i]);

    cout<<mx<<endl;

    auto stopTime = curTime();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    //cout<<"Program ran for "<<(ld)duration.count()/1e6<<" "<<"seconds"<<endl;
}
