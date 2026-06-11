#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {
  string s;
  cin >> s;
  ll n = s.length();

  ll ans = 0;
  ll cnt = 0;
  for (auto &p : s) {
    if (p == 'B') {
      cnt++;
    } else {
      ans += cnt;
    }
  }
  cout << ans << endl;
}