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
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int n, a, b, c, d;
string s;

void solve(istream& cin, ostream& cout) {
  cin >> n >> a >> b >> c >> d;
  a--, b--, c--, d--;
  cin >> s;
  bool ans = true;
  FOR(i, a, c - 2) {
    if (s[i] == '#' && s[i + 1] == '#') ans = false;
  }
  FOR(i, b, d - 2) {
    if (s[i] == '#' && s[i + 1] == '#') ans = false;
  }
  if (c > d) {
    bool tmp = false;
    FOR(i, b - 1, d - 1) {
      if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') tmp = true;
    }
    if (!tmp) ans = false;
  }
  if (ans) cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
