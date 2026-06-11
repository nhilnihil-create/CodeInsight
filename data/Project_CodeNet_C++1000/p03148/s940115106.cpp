#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<pdd> vdd;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(x) (x).begin(),(x).end()
#define INF 1000000000000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    ll n,k;
    cin>>n>>k;
    vvl s(n);
    rep(i,n){
        int t,d;
        cin>>t>>d;
        t--;
        s[t].PB(d);
    }
    rep(i,n){
        sort(all(s[i]));
        reverse(all(s[i]));
        if(s[i].empty())s[i].PB(-1e9);
    }
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) { return a[0] > b[0];});
    ll ans=0;
    priority_queue<ll>q;
    rep(i,k){
        ans+=s[i][0];
        for(int j=1;j<s[i].size();++j)q.push(s[i][j]);
    }
    for(int i=k;i<n;++i)rep(j,s[i].size())q.push(s[i][j]);
    ll z=ans;
    ans+=k*k;
    for(ll i=k-1;i>=1;--i){
        ll x=s[i][0],y=q.top();
        if(x<y){
            q.pop();
            q.push(x);
            z+=y-x;
        }
        ans=max(ans,z+i*i);
    }
    cout<<ans<<endl;
}
