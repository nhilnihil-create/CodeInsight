#include <bits/stdc++.h>
using namespace std;

string s;

string solve();

int main() {
  cin >> s;
  cout << solve() << endl;
  return 0;
}

string solve() {
  if (s == "zyxwvutsrqponmlkjihgfedcba") return "-1";
  vector<bool> ch(26, 0);
  for (int i = 0; i < s.size(); ++i) ch[s[i] - 'a'] = 1;
  if (s.size() != 26)
    for (int i = 0; i < 26; ++i)
      if (!ch[i]) return s += ('a' + i);
  string t = s, res;
  next_permutation(t.begin(), t.end());
  for (int i = 0; i < 26; ++i) {
    res += t[i];
    if (t[i] != s[i]) break;
  }
  return res;
}