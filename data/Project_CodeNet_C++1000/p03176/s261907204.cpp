#include <iostream>
#include <vector>
#include <functional>
using namespace std;
using ll = long long;
#define in(v) v; cin >> v;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
constexpr int MAX_N = 2e5;
int h[MAX_N], a[MAX_N];
template<class T> struct SegTree {
  private:
    int size;
    vector<T> v;
    using F = function<T(T,T)>;
    T default_value; F f;
  public:
    constexpr SegTree(int n, T default_value, F f) : default_value(default_value), f(f) {
      size = 1; while (size < n) size *= 2;
      v.resize(2 * size - 1, default_value);
    }
    constexpr void update(int index, T val) {
      index = index + size - 1;
      v[index] = val;
      while (index > 0) {
        index = (index - 1) / 2;
        v[index] = f(v[2 * index + 1], v[2 * index + 2]);
      }
    }
    constexpr T query(int l, int r) { return query(l, r, 0, size, 0); }
    constexpr T query(int l, int r, int cur_l, int cur_r, int index) {
      if (cur_r <= l || r <= cur_l) return default_value;
      if (l <= cur_l && cur_r <= r) return v[index];

      int mid = (cur_l + cur_r) / 2;
      return f(query(l, r, cur_l, mid, 2 * index + 1), query(l, r, mid, cur_r, 2 * index + 2));
    }
};

constexpr int INF = 1e9;
int main() {
  int in(N);

  SegTree<ll> T(N+1, -INF, [](ll a, ll b){return max(a, b);}); // 範囲max
  T.update(0, 0);

  rep(i, N) cin >> h[i];
  rep(i, N) cin >> a[i];

  rep(i, N) T.update(h[i], T.query(0, h[i]) + a[i]);

  cout << T.query(0, N+1) << endl;
  return 0;
}
