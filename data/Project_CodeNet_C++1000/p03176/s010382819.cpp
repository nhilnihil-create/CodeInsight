#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using Tup = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define prt(v) cout<<(v)<<"\n";
#define fl cout<<flush;
#define fi(v) get<0>(v)
#define se(v) get<1>(v)
#define th(v) get<2>(v)
#define endl "\n"
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld pi=3.141592653589793238;

/* RMQ：[0,n-1] について、区間ごとの最大値を管理する構造体
    update(a,b,x): 区間[a,b) の要素を x に更新。O(log(n))
    update(a,x): a番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) での最大の要素を取得。O(log(n))
    get(a): a番目の要素を取得。O(log(n))
*/
template <typename T>
struct RMQ {
    ll n;
    vector<T> dat, lazy;
    RMQ(ll n_) : n(), dat(n_ * 4, -INF), lazy(n_ * 4, -INF) {
        ll x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    /* lazy eval */
    void eval(ll k) {
        if (lazy[k] == -INF) return;  // 更新するものが無ければ終了
        if (k < n - 1) {             // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        // 自身を更新
        dat[k] = lazy[k];
        lazy[k] = -INF;
    }
    void update(ll a, ll b, T x, ll k, ll l, ll r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(ll a, ll b, T x) { update(a, b, x, 0, 0, n); }
    void update(ll a, T x){ update(a, a + 1, x, 0, 0, n); }
    T query_sub(ll a, ll b, ll k, ll l, ll r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return -INF;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return max(vl, vr);
        }
    }
    T query(ll a, ll b) { return query_sub(a, b, 0, 0, n); }
    T get(ll a){ return query_sub(a, a + 1, 0, 0, n); }
    /* debug */
    inline T operator[](ll a) { return query(a, a + 1); }
    void prll() {
        for (ll i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

signed main(void){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> h(N,0);
    vector<ll> a(N,0);
    for(ll i=0;i<N;++i)cin>>h[i];
    for(ll i=0;i<N;++i)cin>>a[i];
    RMQ<ll> tree(N+1);
    tree.update(0,0);
    for(ll i=0;i<N;++i){
        tree.update(h[i],tree.query(0,h[i])+a[i]);
    }
    prt(tree.query(0,N+1))

    return 0;
}
