#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)

const ll MOD = 1e9 + 7;

void solve(istream& cin, ostream& cout) {
  int h, w, n;
  cin >> h >> w >> n;
  int r, c;
  cin >> r >> c;
  string s, t;
  cin >> s >> t;
  map<char, int> sc, tc;
  sc['L'] = 0;
  sc['R'] = 0;
  sc['U'] = 0;
  sc['D'] = 0;
  tc['L'] = 0;
  tc['R'] = 0;
  tc['U'] = 0;
  tc['D'] = 0;
  REP(i, n) {
    sc[s[i]]++;
    tc[t[i]]++;
  }

  int er = r, ec = c;

  /* Lに落とす */
  REP(i, n) {
    if (s[i] == 'L') {
      ec--;
    }
    if (ec == 0) {
      cout << "NO" << endl;
      return;
    }
    if (ec < w && t[i] == 'R') {
      ec++;
    }
  }

  ec = c;
  /* Rに落とす */
  REP(i, n) {
    if (s[i] == 'R') {
      ec++;
    }
    if (ec == w + 1) {
      cout << "NO" << endl;
      return;
    }
    if (ec > 1 && t[i] == 'L') {
      ec--;
    }
  }

  /* Uに落とす */
  REP(i, n) {
    if (s[i] == 'U') {
      er--;
    }
    if (er == 0) {
      cout << "NO" << endl;
      return;
    }
    if (er < h && t[i] == 'D') {
      er++;
    }
  }

  er = r;
  /* Dに落とす */
  REP(i, n) {
    if (s[i] == 'D') {
      er++;
    }
    if (er == h + 1) {
      cout << "NO" << endl;
      return;
    }
    if (er > 1 && t[i] == 'U') {
      er--;
    }
  }
  cout << "YES" << endl;
}

#ifndef TEST
int main() {
  solve(cin, cout);
}
#endif
