#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define zad tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
using namespace std;
#define in1(x) scanf("%lld",&x)
#define in2(x,y) scanf("%lld%lld",&x,&y)
#define in3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define out(x) printf("%lld",x)
#define outspace(x) printf("%lld ",x)
#define outln(x) printf("%lld\n",x)
#define ll long long
#define ld long double
#define pb push_back
#define p push
#define mkp make_pair
#define ff first
#define PLL pair<ll,ll>
#define PSS pair<string,string>
#define ss second
#define precision(x,d) cout<<fixed<<setprecision(d)<<x
#define minQueue priority_queue<ll,vector<ll>,greater<ll> >
#define maxQueue priority_queue<ll,vector<ll>,less<ll> >
#define all(x) x.begin(),x.end()
#define F(i,a,b) for(ll i=a;i<b;i++)
#define RF(i,a,b) for(ll i=a;i>b;i--)
#define mset(a,b) memset((a),(b),sizeof((a)))
#define IOS ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);srand(time(NULL));
#define MOD 1000000007
#define RMOD 998244353
#define INF 10000000000000000
#define MINF LONG_LONG_MIN
#define MAXF LONG_LONG_MAX
const ll N=200007;
#define OuterLoop ll t;scanf("%lld",&t);while(t--)
#define lcm(a,b) a*b/(__gcd(a,b))
//v =  vector< vector<ll> >(n+1);
//v.assign(n+1,vector<ll>()); this way we can assign anything.
bool isPrime(ll n){
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    ll p=sqrt(n);
    for(int i=5;i<=p;i+=6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;
    return true;
}
ll n;
vector<ll> v;
vector<ll> dp(N,-1);

ll dynamic(ll src)
{
    if(dp[src]!=-1) return dp[src];
    if(src>=n) return dp[src]=0;
    ll cnt=N,cnt1;
    cnt = abs(v[src]-v[src+1])+dynamic(src+1);
    if(src+2<=n) cnt1=abs(v[src]-v[src+2])+dynamic(src+2);
    //cout << src << "--" << cnt << "--" << cnt1 << "\n";
    return dp[src]=min(cnt,cnt1);
}

int main()
{  
    IOS
    ll t=1;
    //cin>>t;
    while(t--)
    {
      cin >> n;
      v = vector<ll>(n+1);
      for(ll i=1;i<=n;i++) cin>>v[i];
    }
    cout << dynamic(1);
    //for(ll i=1;i<=n;i++) cout<<dp[i]<<" ";
}