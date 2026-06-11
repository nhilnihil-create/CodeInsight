#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s, t, u;
  cin >> s >> t;

  int n = s.size(), m = t.size();

  for (int i = n - m; i >= 0; i--) {
    bool ok = true;
    for (int j = 0; j < m; j++) {
      if (!(s[i + j] == t[j] || s[i + j] == '?')) ok = false;
    }
    if (ok) {
      for (int j = 0; j < i; j++) {
        if (j < i && s[j] == '?')
          cout << "a";
        else if (j < i && s[j] != '?')
          cout << s[j];
      }
      cout << t;
      for (int j = i + m; j < n; j++) {
        if (j >= i + m && s[j] == '?')
          cout << "a";
        else if (j && s[j] != '?')
          cout << s[j];
      }
      cout << endl;
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
}