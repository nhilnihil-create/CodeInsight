#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> x(N);
  REP(i, N) cin >> x[i];
  vector<ll> p(0), m(0);
  REP(i, N) {
    if (x[i] < 0) {
      m.push_back(abs(x[i]));
    } else {
      p.push_back(abs(x[i]));
    }
  }
  sort(m.begin(), m.end());
  sort(p.begin(), p.end());
  ll ans = 1e14;
  if (K <= p.size()) {
    ans = min(ans, abs(p[K - 1]));
  }
  if (K <= m.size()) {
    ans = min(ans, abs(m[K - 1]));
  }
  REP(i, p.size()) {
    ll tmp = abs(p[i]);
    if (m.size() <= K - 2 - i) continue;
    tmp += abs(abs(m[K - 2 - i]));
    tmp += min(abs(p[i]), abs(m[K - 2 - i]));
    ans = min(tmp, ans);
  }
  REP(i, m.size()) {
    ll tmp = abs(m[i]);
    if (p.size() <= K - 2 - i) continue;
    tmp += abs(abs(p[K - 2 - i]));
    tmp += min(abs(m[i]), abs(p[K - 2 - i]));
    ans = min(tmp, ans);
  }
  cout << ans << endl;
}