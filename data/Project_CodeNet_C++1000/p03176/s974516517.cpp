#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define print(x) cout << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T> >
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

const ll INF = (1LL << 31)-1;
/**
* @brief セグメント木
* @details 抽象化した遅延セグメント木\n
* 区間更新区間max d1=d0=INT_MAX f=max(a,b) g=h=(b==INT_MAX?a:b)\n
* 区間加算区間和  d1=d0=0 f=g=h=a+b p=a*b\n
* 区間加算区間min d1=d0=0 f=min(a,b) g=h=a+b\n
* 区間更新区間和  d1=d0=0 f=a+b g=h=(b==0?a:b) p=a*b\n
* 区間xor区間和   d1=d0=0 f=a+b g=(b>=1?b-a:a) h=a^b p=a*b
*/
template <typename T, typename E>
struct lazySegTree {
  using F = function<T(T,T)>;
  using G = function<T(T,E)>;
  using H = function<E(E,E)>;
  using P = function<E(E,int)>;
  F f; G g; H h; P p; T d1; E d0;
  int n;
  vector<T> dat;
  vector<E> lazy;

  lazySegTree(){}
  lazySegTree(int n_, F f_, G g_, H h_, 
    T d1_, E d0_, P p_=[](E a, int b){return a;})
    : f(f_), g(g_), h(h_), p(p_), d1(d1_), d0(d0_) 
  {
    n = 1; while(n < n_) n *= 2;
    dat.assign(n*2-1, d1);
    lazy.assign(n*2-1, d0);
  }
  void build(vector<T> v) {
    rep(i, v.size()) dat[i+n-1] = v[i];
    for(int i=n-2; i>=0; --i) dat[i] = f(dat[i*2+1], dat[i*2+2]);
  }

  // 区間の幅がlenの節点kについて遅延評価
  inline void eval(int len, int k) {
    if(lazy[k] == d0) return;
    if(k*2+1 < n*2-1) {
      lazy[2*k+1] = h(lazy[k*2+1], lazy[k]);
      lazy[2*k+2] = h(lazy[k*2+2], lazy[k]);
    }
    dat[k] = g(dat[k],p(lazy[k],len));
    lazy[k] = d0;
  }
  // [a, b)
  T update(int a, int b, E x, int k, int l, int r) {
    eval(r-l, k);
    if(b <= l || r <= a) return dat[k];
    if(a <= l && r <= b) {
      lazy[k] = h(lazy[k], x);
      return g(dat[k], p(lazy[k],r-l));
    }
    return dat[k] = f(update(a, b, x, 2*k+1, l, (l+r)/2),
                      update(a, b, x, 2*k+2, (l+r)/2, r));
  }
  T update(int a, int b, E x) { return update(a, b, x, 0, 0, n); }
  // [a, b)
  T query(int a, int b, int k, int l, int r) {
    eval(r-l, k);
    if(a <= l && r <= b) return dat[k];
    bool left = !((l+r)/2 <= a || b <= l), right = !(r <= 1 || b <= (l+r)/2);
    if(left&&right) return f(query(a, b, 2*k+1, l, (l+r)/2), query(a, b, 2*k+2, (l+r)/2, r));
    if(left) return query(a, b, 2*k+1, l, (l+r)/2);
    return query(a, b, 2*k+2, (l+r)/2, r);
  }
  T query(int a, int b) { return query(a, b, 0, 0, n); }
  // デバッグ出力
  void debug() {
    cout << "---------------------" << endl;
    int cnt = 0;
    for(int i=1; i<=n; i*=2) {
      rep(j, i) {
        cout << "(" << dat[cnt] << "," << lazy[cnt] << ") "; 
        cnt++;
      }
      cout << endl;
    }
    cout << "---------------------" << endl;
  }
};

ll dp[200200];

int main() {
  int n;
  cin >> n;
  vl h(n),a(n);
  rep(i,n)cin >> h[i];
  rep(i,n)cin >> a[i];
  vector<ll> idx(n);
  iota(rng(idx), 0);
  sort(rng(idx), [&](ll l, ll r){
    return h[l] < h[r]; 
  });
  auto f = [](ll a, ll b) { return max(a,b); };
  auto g = [](ll a, ll b) { return (b==0?a:b); };
  
  lazySegTree<ll,ll> seg(n, f, g, g, 0, 0);  
  vector<ll> dp(n);

  rep(i, n) {
    // 高さiの花を追加するか?
    // [0,idx[i])でdpの値が最大のもの
    dp[i] = (idx[i]==0?0:seg.query(0, idx[i])) + a[idx[i]];
    seg.update(idx[i], idx[i]+1, dp[i]);
  }

  ll ans = 0;
  rep(i, n) maxs(ans, dp[i]);
  cout << ans << endl;
  return 0; 
}