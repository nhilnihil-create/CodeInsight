#include <cctype>
#include <iostream>

using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  int index = 0;
  bool ok = true;
  for (int i = 0; i < a; i++) {
    if (!isdigit(s[index++])) {
      ok = false;
    }
  }
  if (s[index++] != '-') {
    ok = false;
  }
  for (int i = 0; i < b; i++) {
    if (!isdigit(s[index++])) {
      ok = false;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
