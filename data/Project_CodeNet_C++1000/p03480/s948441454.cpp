#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define FORR(i, m, n) for (int i = m; i >= n; i--)
#define ALL(x) (x).begin(), (x).end()

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1e15;

int main() {
  string s;
  cin >> s;
  ll n = s.size();
  ll ans = n;
  ll cnt = 0;
  REP(i, n - 1) {
    if (s[i] != s[i + 1]) {
      ++cnt;
      ll l = max((ll)i + 1, n - 1 - i);
      ans = min(ans, l);
    }
  }
  if (cnt == 0) ans = n;
  cout << ans << endl;
  return 0;
}