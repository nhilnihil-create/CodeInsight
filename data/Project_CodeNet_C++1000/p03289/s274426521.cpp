#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool ok(string s) {
  if (s[0] != 'A') return false;
  if (count(s.begin() + 2, s.end() - 1, 'C') != 1) return false;
  for (char c : s) {
    if (c != 'A' && c != 'C' && isupper(c)) return false;
  }
  return true;
}

int main() {
  string s;
  cin >> s;
  cout << (ok(s) ? "AC" : "WA") << endl;
}
