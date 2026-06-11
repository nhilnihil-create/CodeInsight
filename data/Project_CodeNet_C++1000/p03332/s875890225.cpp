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
    vector<ll> vec(1001001,1);
    rep(i,1001000) vec[i+1]=(vec[i]*(i+1))%MOD;
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
    ll ans=0;
    for(ll p=0; p<=n; p++) {
        if((k-a*p)%b!=0) continue;
        ll q=(k-a*p)/b;
        if(q<0 || q>n) continue;
        ans+=(comb(n,p)*comb(n,q))%MOD;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
