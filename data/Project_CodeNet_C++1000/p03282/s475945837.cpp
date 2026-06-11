#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  int ans = 1;
  rep(i, min(k, (ll)s.size())) {
    if (s[i] != '1') {
      ans = s[i] - '0';
      break;
    }
  }
  cout << ans << endl;
  return 0;
}