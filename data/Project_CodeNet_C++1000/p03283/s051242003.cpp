#define _DEBUG 1
#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#ifdef _DEBUG
#define dump(x) cerr << #x << "=" << x << endl
#define dump2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define dump3(x, y, z)                                                     \
  cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define check(s) cerr << s << endl
#else
#define dump(x)
#define dump2(x, y)
#define dump3(x, y, z)
#define check(s)
#endif

#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define unique(v) v.erase(unique(v.begin(), v.end()), v.end());

const ll LINF = 2e18;
const int INF = 1e9;

void solve(ll N, ll M, ll Q, std::vector<ll> L, std::vector<ll> R,
           std::vector<ll> p, std::vector<ll> q) {
  vector<vector<ll>> sum(N + 1, vector<ll>(N + 1, 0));
  rep(i, M) sum.at(L.at(i)).at(R.at(i))++;

  FOR(i, 1, N + 1) {
    FOR(j, 1, N + 1) {
      sum.at(i).at(j) += sum.at(i - 1).at(j);
      sum.at(i).at(j) += sum.at(i).at(j - 1);
      sum.at(i).at(j) -= sum.at(i - 1).at(j - 1);
    }
  }

  rep(i, Q) {
    ll l = p.at(i);
    ll r = q.at(i);
    ll ans = sum.at(r).at(r) - sum.at(r).at(l - 1) - sum.at(l - 1).at(r) +
             sum.at(l - 1).at(l - 1);
    cout << ans << endl;
  }
}

int main() {
  ll N;
  scanf("%lld", &N);
  ll M;
  scanf("%lld", &M);
  ll Q;
  scanf("%lld", &Q);
  std::vector<ll> L(M);
  std::vector<ll> R(M);
  for (int i = 0; i < M; i++) {
    scanf("%lld", &L[i]);
    scanf("%lld", &R[i]);
    L.at(i);
    R.at(i);
  }
  std::vector<ll> p(Q);
  std::vector<ll> q(Q);
  for (int i = 0; i < Q; i++) {
    scanf("%lld", &p[i]);
    scanf("%lld", &q[i]);
    p.at(i);
    q.at(i);
  }
  solve(N, M, Q, std::move(L), std::move(R), std::move(p), std::move(q));
  return 0;
}
