#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

#define P pair<ll, ll>
#define FOR(i, n, m) for (ll i = n; i < (ll)m; i++)
#define FORr(i, m, n) for (ll i = n; i >= (ll)m; i--)
#define FORm(i, m) for (auto i = m.begin(); i != m.end(); i++)
#define sortAl(v) sort(v.begin(), v.end())
#define sortAlr(v)                                                             \
  sort(v.begin(), v.end());                                                    \
  reverse(v.begin(), v.end())
#define cout(n) cout << fixed << setprecision(n)

#define rep(i, n) for (int i = 0; i < n; i++)
#define REP(i, n) for (int i = 1; i < n; i++)
#define all(v) v.begin(), v.end()
template <class T> inline void chmax(T &a, T b) { a = std::max(a, b); }
template <class T> inline void chmin(T &a, T b) { a = std::min(a, b); }

#define mod (int)(1e9 + 7)
#define INF LLONG_MAX

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, K;
  cin >> N >> K;

  if (N % K == 0) {
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }

  return 0;
}
