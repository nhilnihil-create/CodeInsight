#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n-1);i>=0;i--)
#define FOR(i,n,m) for(int i=n;i<=(int)(m);i++)
#define RFOR(i,n,m) for(int i=(int)(n);i>=m;i--)
#define all(x) (x).begin(),(x).end()
#define sz(x) int(x.size())
typedef long long ll;
const int INF = 1e9;
const int MOD = 998244353;
const ll LINF = 1e18;
const double PI=3.14159265358979323846;
using namespace std;
vector<int> dx={1,0,-1,0};
vector<int> dy={0,1,0,-1};
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

ll ext_gxd(ll a,ll b,ll &x,ll &y) {
    if(b==0) {
        x=1;
        y=0;
        return a;
    }
    ll q = a/b;
    ll g = ext_gxd(b,a-q*b,x,y);
    ll z = x-q*y;
    x=y;
    y=z;
    return g;
}

ll modinv(ll a, ll m) {
    ll x,y;
    ext_gxd(a,m,x,y);
    x%=m;
    if(x<0) x+=m;
    return x;
}

vector<ll> kaijou() {
    vector<ll> vec(1000010,1);
    rep(i,1000000) vec[i+1]=(vec[i]*(i+1))%MOD;
    return vec;
}

vector<ll> kai;
ll comb(int x,int y) {
    if(x<y || y<0)  return 0;
    return kai[x]*modinv(kai[x-y]*kai[y],MOD)%MOD;
}


int main() {
    kai=kaijou();
    ll n,a,b,k;
    cin>>n>>a>>b>>k;
    ll x,y;
    ll g=ext_gxd(a,b,x,y);
    if(k%g!=0) {
        cout<<0<<endl;
        return 0;
    }
    x*=k/g;
    y*=k/g;
    ll l=ceil(max((double)-g*x/b,(double)-g*(n-y)/a));
    ll r=floor(min((double)g*(n-x)/b,(double)g*y/a));
    //cout<<x<<" "<<y<<" "<<g<<" "<<l<<" "<<r<<endl;
    
    ll ans=0;
    for(ll K=l; K<=r; K++) {
        ll X=x+K*b/g;
        ll Y=y-K*a/g;
       ans+=comb(n,X)*comb(n,Y)%MOD;
       ans%=MOD;
    }
    cout<<ans<<endl;
}
