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
  string S, T;
  cin >> S >> T;
  reverse(S.begin(), S.end());
  reverse(T.begin(), T.end());
  REP(i, S.size() - T.size() + 1) {
    bool b = true;
    REP(j, T.size()) {
      if (S[i + j] == '?') continue;
      if (S[i + j] != T[j]) b = false;
    }
    if (!b) continue;
    string st = S;
    REP(j, T.size()) { st[i + j] = T[j]; }
    REP(j, st.size()) {
      if (st[j] == '?') st[j] = 'a';
    }
    reverse(st.begin(), st.end());
    cout << st << endl;
    return 0;
  }
  cout << "UNRESTORABLE " << endl;
}