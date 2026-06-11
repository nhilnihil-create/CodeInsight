#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  ll ans = 0, cntA = 0;
  rep(i, s.size()) {
    if (s.substr(i, 2) == "BC") ans += cntA, i++;
    else if (s[i] == 'A') cntA++;
    else cntA = 0;
  }
  cout << ans << endl;

  return 0;
}
