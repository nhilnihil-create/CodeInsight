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
    int n,m;
    cin>>n>>m;
    vl x(n),y(n),z(n);
    rep(i,n)cin>>x[i]>>y[i]>>z[i];
    vvl a(8);
    rep(i,n){
        int cnt=0;
        ll X,Y,Z;
        rep(j,2){
            rep(k,2){
                rep(l,2){
                    if(j==0)X=x[i];
                    else X=-x[i];
                    if(k==0)Y=y[i];
                    else Y=-y[i];
                    if(l==0)Z=z[i];
                    else Z=-z[i];
                    a[cnt].PB(X+Y+Z);
                    cnt++;
                }
            }
        }
    }
    rep(i,8){sort(all(a[i]));reverse(all(a[i]));}
    ll ans=-1e18;
    rep(i,8){
        ll sum=0;
        rep(j,m)sum+=a[i][j];
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
}