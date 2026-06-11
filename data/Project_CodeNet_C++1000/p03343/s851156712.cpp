#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
    ll to, rev;
    long double cap;
    Edge(ll _to, long double _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,
              long double revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

void solve() {
    ll n, k, q;
    cin >> n >> k >> q;
    vec<ll> a(n);
    REP(i, n) cin >> a[i];
    vec<ll> b = a;
    sort(all(b));
    ll ans = b[q - 1] - b[0];
    //cout << b[q - 1] << " " << b[0] << en;

    REP(i,n) {
        vvec<ll> aa(1);
        vec<ll> ret;
        int pos = 0;
        REP(j,n){
            if(b[i]<a[j]){
                aa[pos].push_back(a[j]);
            }else{
                if(aa[pos].size()){
                    sort(all(aa[pos]));
                    pos++;
                    aa.push_back(vec<ll>());
                }
            }
        }
        sort(all(aa[pos]));

        auto check = [&](ll x) {
            ll con = 0;
            REP(j,aa.size()){
                if(aa[j].size() < k)
                    continue;
                auto it = upper_bound(all(aa[j]), b[x]);
                con += min((ll)aa[j].size() - k + 1, (ll)(it - aa[j].begin()));
            }
            return con >= q;
        };

        ll l = i;
        ll r = n;
        while(l+1<r){
            ll m = l + r >> 1;
            if(check(m)) r = m;
            else l = m;
        }
        if(r == n) continue;
        chmin(ans, b[r] - b[i + 1]);
        //cout << b[r] << " " << b[i + 1] << en;

    }
    cout << ans << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    // ll t;cin>>t;REP(i,t) solve();

    return 0;
}
