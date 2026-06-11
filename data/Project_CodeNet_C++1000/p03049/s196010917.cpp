#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  ll ans = 0;
  ll ra = 0, lb = 0, katu = 0;

  REP(i, N) {
    cin >> s[i];
    REP(j, s[i].size() - 1) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B') ans++;
    }
    if (s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A') {
      katu++;
      continue;
    }
    if (s[i][0] == 'B') lb++;
    if (s[i][s[i].size() - 1] == 'A') ra++;
  }
  if (ra == 0 && lb == 0) {
    katu--;
  }

  cout << max(ans + min(ra, lb) + max(katu, (ll)0), (ll)0) << endl;
}