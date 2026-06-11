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
#define OPTIMIZE_STDIO ios::sync_with_stdio(false);cin.tie(0);cout.precision(10);cout << fixed
#define endl '\n'

const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LINF = 1e18;

map<int, int> mp;

void decomposit(int j) {
  int s = sqrt(j);
  FOR(i, 2, s) {
    while (j % i == 0) {
      mp[i]++;
      j /= i;
    }
  }
  if (j != 1) mp[j]++;
}

void solve(istream& cin, ostream& cout) {
  int n;
  cin >> n;
  mp.clear();
  FOR(i, 2, n) decomposit(i);
  int cnt_75 = 0, cnt_25 = 0, cnt_15 = 0, cnt_5 = 0, cnt_3 = 0;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    int cnt = it->second;
    if (cnt >= 74) {
      cnt_75++; cnt_25++; cnt_15++; cnt_5++; cnt_3++;
    } else if (cnt >= 24) {
      cnt_25++; cnt_15++; cnt_5++; cnt_3++;
    } else if (cnt >= 14) {
      cnt_15++; cnt_5++; cnt_3++;
    } else if (cnt >= 4) {
      cnt_5++; cnt_3++;
    } else if (cnt >= 2)
      cnt_3++;
  }
  int ans = 0;
  ans += cnt_75;
  ans += cnt_25 * (cnt_3 - 1);
  ans += cnt_15 * (cnt_5 - 1);
  ans += cnt_5 * (cnt_5 - 1) * (cnt_3 - 2) / 2;
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
}
#endif
