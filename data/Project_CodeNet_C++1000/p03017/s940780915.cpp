#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define RFOR(i, m, n) for (int i = (m - 1); i >= 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, n, 0)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define print(ele) cout << ele << endl
#define print10(ele) cout << fixed << setprecision(10) << ele << endl

using namespace std;
typedef long long ll;
typedef vector<int> ivec;
typedef vector<string> svec;
typedef vector<ll> lvec;

const int mod = 1e9 + 7;
const ll INF = 1000000000000000000LL;

int main() {
  int n, a, b, c, d;
  char s[1001000];
  // cin >> n >> a >> b >> c >> d >> s;

  scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
  scanf("%s", s + 1);

  FOR(i, a, c) {
    if (s[i] == '#' && s[i + 1] == '#') return print("No"), 0;
  }
  FOR(i, b, d) {
    if (s[i] == '#' && s[i + 1] == '#') return print("No"), 0;
  }

  if (c > d) {
    bool bo = false;
    for (int i = b; i <= d; i++)
      if (s[i] == '.' && s[i + 1] == '.' && s[i - 1] == '.') bo = true;
    if (!bo) return puts("No"), 0;
  }
  print("Yes");
  return 0;
}