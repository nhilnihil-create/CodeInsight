#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;
  bool found = 0;
  for (int i = 0; i < s.length() - t.length() + 1; i++) {
    int count = 0;
    for (int j = 0; j < t.length(); j++) {
      if (s[s.length() - i - j - 1] == t[t.length() - j - 1] ||
          s[s.length() - i - j - 1] == '?') {
        count += 1;
        if (count == t.length()) {
          found = 1;
        }
      } else
        break;
    }
    if (found) {
      for (int j = 0; j < t.length(); j++) {
        s[s.length() - i - j - 1] = t[t.length() - j - 1];
      }
      break;
    }
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?')
      s[i] = 'a';
  }
  if (found)
    cout << s << endl;
  else
    cout << "UNRESTORABLE" << endl;
}
