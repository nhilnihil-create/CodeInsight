#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const int MAX = 100000;

int main() {
  int q;
  cin >> q;

  V<int> l(q), r(q);
  rep(i, q) cin >> l[i] >> r[i];

  V<int> F(MAX + 10);
  for (int i = 2; i <= MAX; i++) {
    for (int j = i; j <= MAX; j += i) F[j]++;
  }

  int c = 0;
  V<int> cnt(MAX + 10);
  for (int i = 1; i <= MAX; i += 2) {
    if (F[i] == 1) {
      if (F[(i + 1) / 2] == 1) c++;
    }
    cnt[i] = c;
  }

  rep(i, q) {
    int ans = cnt[r[i]] - cnt[l[i] - 2];
    printf("%d\n", ans);
  }
}
