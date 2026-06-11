#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

string replace_all(string str, string from, string to) {
  int fromSize = from.size();
  int toSize = to.size();
  int pos = str.find(from);

  while (pos != std::string::npos) {
    str.replace(pos, fromSize, to);
    pos = str.find(from, pos + toSize);
  }
  return str;
}

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  int len = s.size();
  string s_d = replace_all(s, "BC", "D");
  int a_cnt = 0;
  REP(i, s_d.size()) {
    if (s_d[i] == 'A') {
      a_cnt++;
    } else if (s_d[i] == 'D') {
      ans += a_cnt;
    } else {
      a_cnt = 0;
    }
  }
  cout << ans << endl;
}