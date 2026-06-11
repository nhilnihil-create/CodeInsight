#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;

int main() {
  string s;
  cin >> s;

  int S = s.length();
  if (S < 26) {
    set<char> c;
    rep(i, 26) c.insert('a' + i);
    rep(i, S) c.erase(s[i]);
    cout << s << *c.begin() << endl;
    return 0;
  }

  if (s == "zyxwvutsrqponmlkjihgfedcba") {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 25; i >= 0; i--) {
    string sub = s.substr(0, i);
    char c = s[i] + 1;
    while (c <= 'z') {
      if (sub.find(c) == sub.npos) {
        cout << sub << c << endl;
        return 0;
      }
      c++;
    }
  }
}
