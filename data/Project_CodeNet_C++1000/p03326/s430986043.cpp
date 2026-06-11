#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <cmath>
#include <bitset>
#include <cctype>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
    auto val = table(args...);
    return vector<decltype(val)>(n, move(val));
}
const ll INF = 1e16;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
const ll MAX = 200005;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    ll x[n],y[n],z[n];
    ll nx[n],ny[n],nz[n];
    rep(i,n){
        cin >> x[i] >> y[i] >> z[i];
    }
    ll ans = 0;
    rep(i,(1<<3)){
        if (i&1) rep(i,n) nx[i] = -x[i];
        else rep(i,n) nx[i] = x[i];
        if (i&2) rep(i,n) ny[i] = -y[i];
        else rep(i,n) ny[i] = y[i];
        if (i&4) rep(i,n) nz[i] = -z[i];
        else rep(i,n) nz[i] = z[i];
        vector<P> a;
        rep(i,n){
            a.push_back(P(nx[i]+ny[i]+nz[i],i));
        }
        RSORT(a);
        ll b = 0,d = 0,p = 0,index;
        rep(i,m){
            index = a[i].second;
            b += x[index];
            d += y[index];
            p += z[index];
        }
        chmax(ans,abs(b)+abs(d)+abs(p));
    }
    PRINT(ans);
}
