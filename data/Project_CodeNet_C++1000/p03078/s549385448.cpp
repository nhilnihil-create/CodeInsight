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
    int x,y,z,k;cin>>x>>y>>z>>k;
    vl a(x),b(y),c(z),d;
    rep(i,x)cin>>a[i];
    sort(all(a));
    rep(i,y)cin>>b[i];
    sort(all(b));
    rep(i,z)cin>>c[i];
    sort(all(c));
    rep(i,x)rep(j,y)d.PB(a[i]+b[j]);
    sort(all(d));
    ll r=3e10,l=0;
    while(r-l>1){
        ll m=(r+l)/2;
        int cnt=0;
        rep(i,d.size()){
            int count=c.end()-lower_bound(all(c),m-d[i]);
            cnt+=count;
        }
        if(cnt>=k)l=m;
        else r=m;
    }
    int cnt=0;
    rep(i,d.size()){
        int count=c.end()-lower_bound(all(c),r-d[i]);
        cnt+=count;
    }
    if(cnt>=k)l=r;
    vl ans;
    rep(i,d.size()){
        int s=lower_bound(all(c),l-d[i])-c.begin();
        for(int j=s;j<z;++j){
            ans.PB(d[i]+c[j]);
        }
    }
    sort(all(ans));
    reverse(all(ans));
    rep(i,k)cout<<ans[i]<<endl;
}