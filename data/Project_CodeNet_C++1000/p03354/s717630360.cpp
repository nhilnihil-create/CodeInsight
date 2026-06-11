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
#include <set>
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
int nx[4] = {1,0,-1,0};
int ny[4] = {0,1,0,-1};
class UnionFind{
    private:
        vector<ll> par;
        vector<ll> siz;
    public:
        UnionFind(ll sz){
            par.resize(sz);
            siz.assign(sz,1LL);
            rep(i,sz) par[i] = i;
        }

        ll find(ll x){
            if (par[x] == x) return x;
            else return par[x] = find(par[x]);
        }

        void unite(ll x,ll y){
            x = find(x);
            y = find(y);
            if (x == y) return;
            if (siz[x] < siz[y]) swap(x,y);
            siz[x] += siz[y];
            par[y] = x;
        }

        bool same(ll x,ll y){
            return find(x) == find(y);
        }

        ll size(ll x){
            return siz[find(x)];
        }
};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    UnionFind sw(n);
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int a,b;
    rep(i,m){
        cin >> a >> b;
        a--;
        b--;
        sw.unite(a,b);
    }
    int ans = 0;
    rep(i,n){
        if (sw.same(i,--p[i])) ans++;
    }
    PRINT(ans);
}
