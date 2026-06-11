#include <bits/stdc++.h>
using namespace std;

int main(int, char**) {
  string s;
  cin >> s;

  for (char c : s) {
    if (!isalpha(c)) {
      cout << "WA" << endl;
      return 0;
    }
  }

  if (s.size() == 4) {
    if (s[0] != 'A' || isupper(s[3])) {
      cout << "WA" << endl;
      return 0;
    } else if ((s[1] != 'C' && s[2] != 'C') || (s[1] == 'C' && s[2] == 'C')) {
      cout << "WA" << endl;
      return 0;
    }
    cout << "AC" << endl;
    return 0;
  }

  if (s[0] != 'A' || isupper(s[1])) {
    cout << "WA" << endl;
    return 0;
  }

  int c_count = 0;
  for (int i = 2; i < s.size() - 1; ++i) {
    if (s[i] == 'C') {
      c_count++;
      if (c_count > 1) {
        cout << "WA" << endl;
        return 0;
      }
      continue;
    }

    if (isupper(s[i])) {
      cout << "WA" << endl;
      return 0;
    }
  }

  if (c_count == 0) {
    cout << "WA" << endl;
    return 0;
  }

  for (int i = s.size() - 1; i < s.size(); i++) {
    if (isupper(s[i])) {
      cout << "WA" << endl;
      return 0;
    }
  }

  cout << "AC" << endl;

  return 0;
}
