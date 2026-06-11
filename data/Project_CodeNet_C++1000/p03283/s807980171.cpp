#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, n) for (long long i = 0; i < (n); ++i)
#define repr(i, a, b) for (auto i = (a); i < (b); ++i)
#define itr(x, c) for (auto&& x : (c))
#define updatemax(t, v) ((t) = std::max((t), (v)))
#define updatemin(t, v) ((t) = std::min((t), (v)))
#define endl _endl
const char _endl = (cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout.precision(16), '\n');

void solve(long long N, long long M, long long Q, std::vector<long long> L, std::vector<long long> R, std::vector<long long> p, std::vector<long long> q) {
  vector<vector<ll>> c(N + 1, vector<ll>(N + 1));
  vector<vector<ll>> cs(N + 1, vector<ll>(N + 2));
  rep(i, M) {
    ++c[L[i]][R[i]];
  }
  rep(i, N + 1) rep(j, N + 1) cs[i][j + 1] = cs[i][j] + c[i][j];
  rep(i, Q) {
    ll ans = 0;
    repr(j, p[i], q[i] + 1) ans += cs[j][q[i] + 1] - cs[j][p[i] - 1];
    cout << ans << endl;
  }
}

int main() {
  long long N;
  scanf("%lld", &N);
  long long M;
  scanf("%lld", &M);
  long long Q;
  scanf("%lld", &Q);
  std::vector<long long> L(M);
  std::vector<long long> R(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &L[i]);
    scanf("%lld", &R[i]);
  }
  std::vector<long long> p(Q);
  std::vector<long long> q(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &p[i]);
    scanf("%lld", &q[i]);
  }
  solve(N, M, Q, std::move(L), std::move(R), std::move(p), std::move(q));
}
