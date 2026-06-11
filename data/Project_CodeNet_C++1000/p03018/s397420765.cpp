#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s, t;
  cin >> s;
  int n = s.size();
  // s.push_back('-');
  for (int i = 0; i < n; i++)
    if (s[i] == 'B' && s[i + 1] == 'C')
      t.push_back('D'), i++;
    else
      t.push_back(s[i]);

  ll ans = 0, add = 0;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == 'A')
      add++;
    else if (t[i] == 'D')
      ans += add;
    else
      add = 0;
  }
  cout << ans << endl;
}
