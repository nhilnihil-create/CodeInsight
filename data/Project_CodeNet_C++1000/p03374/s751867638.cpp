#include <bits/stdc++.h>
using namespace std;
struct segment_tree {
  public:
    int n, N;
    vector<long long> tr;
    segment_tree (vector<long long> v) {
      n = v.size();
      N = 1;
      while (N < n) {
        N <<= 1;
      }
      tr.resize(2 * N, 0);
      for (int i = 0; i < n; i++) {
        tr[N + i] = v[i];
      }
      for (int i = N - 1; i >= 1; i--) {
        tr[i] = max(tr[2 * i], tr[2 * i + 1]);
      }
    }
    void update (int i, long long x) {
      i += N;
      tr[i] = x;
      i >>= 1;
      for (; i; i >>= 1) {
        tr[i] = max(tr[2 * i], tr[2 * i + 1]);
      }
    }
    long long getMax (int l, int r, int k = 1, int L = 0, int R = -1) {
      if (R == -1) R = N;
      if (l <= L && R <= r) {
        return tr[k];
      } else if (r <= L || R <= l) {
        return 0;
      } else {
        int C = (L + R) >> 1;
        return max(getMax(l, r, 2 * k, L, C), getMax(l, r, 2 * k + 1, C, R));
      }
    }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> x(n + 2, 0), v(n + 2, 0);
  for (int i = 1; i <= n; i++) cin >> x[i] >> v[i];
  x[n + 1] = k;
  vector<long long> c(n + 1, 0), C(n + 1, 0), d(n + 1, 0), D(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    c[i] = c[i - 1] + v[n + 1 - i] - (x[n + 2 - i] - x[n + 1 - i]);
    C[i] = C[i - 1] + v[n + 1 - i] - ((x[n + 2 - i] - x[n + 1 - i]) << 1);
    d[i] = d[i - 1] + v[i] - (x[i] - x[i - 1]);
    D[i] = D[i - 1] + v[i] - ((x[i] - x[i - 1]) << 1);
  }
  segment_tree cs(c), Cs(C), ds(d), Ds(D);
  long long ret = 0;
  for (int i = 0; i <= n; i++) {
    ret = max(ret, cs.getMax(0, i + 1) + Ds.getMax(0, n + 1 - i));
    ret = max(ret, Cs.getMax(0, i + 1) + ds.getMax(0, n + 1 - i));
  }
  cout << ret << '\n';
  return 0;
}