#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

string replaceAll(string s, string target, string replacement) {
  if (!target.empty()) {
    std::string::size_type pos = 0;
    while ((pos = s.find(target, pos)) != std::string::npos) {
      s.replace(pos, target.length(), replacement);
      pos += replacement.length();
    }
  }
  return s;
}

int main() {
  string s;
  cin >> s;

  // s = replaceAll(s, "BC", "X");

  ll ans = 0;
  ll cntA = 0;
  rep(i, s.size()) {
    if (s.substr(i, 2) == "BC") {
      ans += cntA;
      i++;
    } else if (s[i] == 'A') {
      cntA++;
    } else {
      cntA = 0;
    }
  }
  cout << ans << endl;

  return 0;
}
