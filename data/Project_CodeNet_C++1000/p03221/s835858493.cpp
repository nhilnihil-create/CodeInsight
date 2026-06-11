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
  int N, M;
  cin >> N >> M;
  vector<map<int, int>> p(N + 1);
  vector<string> S(M);
  REP(i, M) {
    int a, b;
    cin >> a >> b;
    p[a][b] = i;
  }
  for (int i = 1; i <= N; i++) {
    int id = 1;
    for (auto s : p[i]) {
      string tmpl = to_string(i);
      string tmpr = to_string(id);
      reverse(tmpl.begin(), tmpl.end());
      reverse(tmpr.begin(), tmpr.end());
      while (tmpl.size() < 6) {
        tmpl.push_back('0');
      }
      while (tmpr.size() < 6) {
        tmpr.push_back('0');
      }
      reverse(tmpl.begin(), tmpl.end());
      reverse(tmpr.begin(), tmpr.end());
      S[s.second] = tmpl + tmpr;
      id++;
    }
  }
  REP(i, S.size()) { cout << S[i] << "\n"; }
}