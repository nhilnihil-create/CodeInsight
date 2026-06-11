#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  string s;
  cin >> s;
  
  string t = "";
  for (int i = 0; i < s.size(); i++) {
    if (i < s.size() - 1) {
      if (s.at(i) == 'B' && s.at(i + 1) == 'C') {
        t += 'D';
        i++;
        continue;
      }
    }
    t += s.at(i);
  }
  
  ll ans = 0, count = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t.at(i) == 'B' || t.at(i) == 'C') count = 0;
    else if (t.at(i) == 'D') ans += count;
    else count++;
  }
  
  cout << ans << '\n';
}