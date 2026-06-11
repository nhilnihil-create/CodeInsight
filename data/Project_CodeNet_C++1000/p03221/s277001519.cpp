#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n, m;
  cin >> n >> m;
  V<int> P(m);
  V<ll> y(m);
  rep(i, m) cin >> P[i] >> y[i];

  V<V<ll>> s(n + 1);
  rep(i, m) s[P[i]].push_back(y[i]);
  rep(i, n + 1) sort(s[i].begin(), s[i].end());

  rep(i, m) {
    int p = P[i];
    auto itr = lower_bound(s[p].begin(), s[p].end(), y[i]);
    int seq = distance(s[p].begin(), itr) + 1;
    printf("%06d%06d\n", p, seq);
  }
}
