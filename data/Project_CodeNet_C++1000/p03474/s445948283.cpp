#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  bool ok = true;
  for (int i = 0; i < s.size(); i++) {
    if (i == a && s.at(i) != '-') {
      ok = false;
    }
    if (i != a && !isdigit(s.at(i))) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  return 0;
}
