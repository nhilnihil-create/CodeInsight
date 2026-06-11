#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  string s, t;
  cin >> s >> t;
  s += s;
  bool ans = false;
  rep(i, s.size()) {
    if (s.substr(i, t.size()) != t) continue;
    ans = true;
    break;
  }
  cout << (ans ? "Yes" : "No") << '\n';
  return 0;
}