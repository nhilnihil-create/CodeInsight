#include <cstdlib>
#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string s;
  cin >> s;
  int l = s.size();
  bool ok = false;
  if (s[0] != 'A') {
    ok = false;
  } else {
    bool match = false;
    for (int i = 1; i < l; ++i) {
      if (i == 1 || i == l - 1) {
        if (!islower(s[i])) {
          match = false;
          break;
        }
      }
      if (s[i] == 'C') {
        if (match) {
          match = false;
          break;
        }
        match = true;
      }
    }
    if (match) {
      ok = true;
    }
  }

  if (ok) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
  return 0;
}
