#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;

  ll b_cnt = 0;
  ll ans = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B') {
      b_cnt++;
    } else {
      ans += b_cnt;
    }
  }

  cout << ans << endl;
}