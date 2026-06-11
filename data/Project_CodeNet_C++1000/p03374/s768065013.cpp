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
    ll n,c;cin>>n>>c;
    vl x(n),v(n);
    vl a1(1,0),a2(1,0),b1(1,0),b2(1,0),c1(1,0),c2(1,0),d1(1,0),d2(1,0);
    rep(i,n)cin>>x[i]>>v[i];
    ll suma=0;
    rep(i,n){
        suma+=v[i];
        if(suma-x[i]>a1[a1.size()-1]){
            a1.PB(suma-x[i]);
            a2.PB(x[i]);
        }
        if(suma-2*x[i]>b1[b1.size()-1]&&x[i]<c/2){
            b1.PB(suma-2*x[i]);
            b2.PB(x[i]);
        }
    }
    ll sumc=0;
    for(int i=n-1;i>=0;--i){
        sumc+=v[i];
        if(sumc-(c-x[i])>c1[c1.size()-1]){
            c1.PB(sumc-(c-x[i]));
            c2.PB(c-x[i]);
        }
        if(sumc-2*(c-x[i])>d1[d1.size()-1]&&(c-x[i])<c/2){
            d1.PB(sumc-2*(c-x[i]));
            d2.PB(c-x[i]);
        }
    }
    ll ans1=a1[a1.size()-1];
    for(int i=1;i<b1.size();++i){
        ll sum=0;
        sum+=b1[i];
        int k=lower_bound(all(c2),c-2*b2[i])-c2.begin();
        sum+=c1[k-1];
        if(ans1<sum)ans1=sum;
    }
    ll ans2=c1[c1.size()-1];
    for(int i=1;i<d1.size();++i){
        ll sum=0;
        sum+=d1[i];
        int k=lower_bound(all(a2),c-2*d2[i])-a2.begin();
        sum+=a1[k-1];
        if(ans2<sum)ans2=sum;
    }
    cout<<max(ans1,ans2)<<endl;
}