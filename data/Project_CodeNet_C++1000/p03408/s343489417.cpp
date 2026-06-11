#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
  int N, M, tmp, result = 0;
  cin >> N;
  vector<string> s(N), u;
  bool can;
  REP(i, N) {
    can = true;
    cin >> s[i];
    REP(j, u.size()) {
      if (s[i] == u[j]) {
        can = false;
        break;
      }
    }
    if (can) {
      u.push_back(s[i]);
    }
  }
  cin >> M;
  vector<string> t(M);
  REP(i, M) {
    cin >> t[i];
  }
  REP(i, u.size()) {
    tmp = 0;
    REP(j, N) {
      if (u[i] == s[j]) {
        tmp++;
      }
    }
    REP(j, M) {
      if (u[i] == t[j]) {
        tmp--;
      }
    }
    if (tmp > result) {
      result = tmp;
    }
  }
  cout << result << endl;
  return 0;
}
