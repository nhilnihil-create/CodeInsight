//dragon->emperor
#include <bits/stdc++.h>

using namespace std;

/*************************************************/

#define mod 1000000007
#define mod2 998244353
const double pi = acos(-1);
#define inf (1ll<<61)-1

#define ll long long
#define ld  long double
#define floop(i,a,n) for(ll i=a;i<n;i++)
#define loopf(i,a,n) for(ll i=n-1;i>=a;i--)
#define space " "
#define TEST(t) ll t; cin>>t; while(t--)
#define r(n) ll n; cin>>n;
#define r1(a,n) ll a[n]; for(ll i=0;i<n;i++) cin>>a[i];
#define p1(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout<<endll;
#define p2(n) cout<<n<<" ";
#define p(n) cout<<n<<endll;

#define endll "\n"
#define pb push_back
#define mp make_pair
#define dec(n) fixed<<setprecision(n)
#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))

typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef map<ll,ll> mll;

bitset<200000>vis(0);
vector<bool> prime;

void primes(ll n)
{
    prime.resize(n+1);
    prime.assign(n+1,true);
    prime[0]=0;
    prime[1]=0;
    for(ll i=2; i*i<=n; i++)
    {
        if(prime[i])
        {
            for(ll j=(i*i); j<n; j=j+i) prime[j]=false;
        }
    }
}

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll gcd(ll x, ll y)
{
    if(x==0) return y;
    return gcd( y%x ,x);
}

ll powM(ll x, ll y, ll m)
{
    ll ans=1, r=1;
    x=x%m;
    while(r>0 && r<=y)
    {
        if(r & y)
        {
            ans=ans*x;
            ans=ans%m;
        }
        r=r<<1;
        x=x*x;
        x=x%m;
    }
    return ans;
}

ll powN(ll a,ll n)
{
    if(n==0) return 1;
    if(n==1) return a;
    ll u=powN(a,n/2);
    u=u*u;
    if(n%2) u=u*a;
    return u;
}

ll modinv(ll a,ll m)
{
    return powM(a,m-2,m);
}

ll ncr(ll n, ll r, ll m)
{
    if(n<r) return 0;
    if(n==r || r==0) return 1;
    if(r==1) return n;
    if(n-r<r) return ncr(n,n-r,m);
    ll a=n;
    ll b=r;
    for(ll i=1; i<r; i++)
    {
        a=(a*(n-i))%m;
        b=(b*(r-i))%m;
    }
    b=modinv(b,m);
    a=(a*b)%m;
    return a;
}

ll countbits(ll n)
{
    ll cot=0;
    while(n)
    {
        cot++;
        n >>= 1;
    }
    return cot;
}

ll check_prime(ll n)
{
    ll ans=1;
    for(ll i=2; i*i<=n; i++)
    {
        if(n%i==0) { ans=0; break;}
    }
    return ans;
}

ll SOD(ll n)
{
    ll sum=0;
    while(n>0)
    {
        sum+=n%10;
        n/=10;
    }
    return sum;
}

ll countsubstring(const string &s, ll n)
{
    ll count=0;
    string ttt="";
    for(ll i=0;i<=n;i++)
    {
        if(s.substr(i,ttt.size())==ttt) count++;
    }
    return count;
}

/*************************************************/
int main()
{    
    fast();
    ll t=1; 
    // cin>> t;
    while(t--)
    {
        ll n; cin>>n;
        vector<ll> dp(3,0);
        floop(tt,0,n)
        {
            vector<ll> c(3);
            floop(i,0,3) cin>>c[i];
            vector<ll> new_dp(3,0);
            floop(i,0,3)
            {
                floop(j,0,3)
                {
                    if(i!=j) new_dp[j]=max(new_dp[j],dp[i]+c[j]);
                }
            }
            dp=new_dp;
        }
        ll ans=max({dp[0],dp[1],dp[2]});
        cout<<ans<<endll;
    }
    return 0;
}