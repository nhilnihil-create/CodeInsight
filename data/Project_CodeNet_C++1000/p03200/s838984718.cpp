#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  string s;
  ll wcnt = 0, ans = 0;
  bool b = false;
  cin >> s;
  rep(i, s.size()) {
    if (s[i] == 'B') b = true;
    if (s[i] == 'W') {
      ans += i - wcnt;
      wcnt++;
    }
  }

  cout << (b ? ans : 0) << endl;
  return 0;
}
