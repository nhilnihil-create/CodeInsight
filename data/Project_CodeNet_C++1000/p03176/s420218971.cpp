#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
struct SegmentTree {
 private:
  ll n;            //最下段のサイズ
  T e;             //単位元
  vector<T> node;  //セグメント木を表現する配列
  typedef function<T(T, T)> Func;
  Func f;  //区間クエリで使う処理

 public:
  SegmentTree(vector<T> v, Func f_input, T e_input) {
    f = f_input;
    e = e_input;
    ll sz = SZ(v);
    n = 1;
    while (n < sz) n *= 2;
    node.resize(2 * n - 1, e);
    REP(i, sz) node[i + n - 1] = v[i];
    IREP(i, n - 1) node[i] = f(node[2 * i + 1], node[2 * i + 2]);
  }

  // x番目(0-indexed)の要素をvalに更新する
  void update(ll x, T val) {
    x += (n - 1);
    node[x] = val;
    while (x > 0) {
      x = (x - 1) / 2;
      node[x] = f(node[2 * x + 1], node[2 * x + 2]);
    }
  }

  // [a, b) に対する区間クエリに答える
  // k := 自分がいるノードのインデックス
  // [l, r) : ノードkの対象区間
  T query(ll a, ll b, ll k = 0, ll l = 0, ll r = -1) {
    if (r < 0) r = n;
    if (r <= a || b <= l) return e;
    if (a <= l && r <= b) return node[k];
    T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return f(vl, vr);
  }

  // 添字でアクセス
  T operator[](ll i) { return node[i + n - 1]; }
};

int main() {
  ll n;
  cin >> n;
  vector<ll> h(n), a(n);
  REP(i, n) {
    cin >> h[i];
    h[i]--;
  }
  REP(i, n) { cin >> a[i]; }
  vector<ll> dp(n, 0);

  SegmentTree<ll> sg(
      dp, [](ll i, ll j) { return max(i, j); }, 0LL);

  REP(i, n) { sg.update(h[i], max(sg[h[i]], sg.query(0, h[i]) + a[i])); }

  ll ans = 0;
  REP(i, n) { chmax(ans, sg[i]); }
  cout << ans << endl;
}