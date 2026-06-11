#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; ++i)

int abcjudge(int a, int b, int c) {
  if (a == b) {
    if (c >= a-1 && c <= a+1) {
      return 1;
    } else {
      return 0;
    }
  } else {
    return 0;
  }
}

int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0;
  REP(i, s.size()) {
    if (s[i] == 'a') {
      ++a;
    } else if (s[i] == 'b') {
      ++b;
    } else {
      ++c;
    }
  }
  if (abcjudge(a, b, c) || abcjudge(a, c, b) || abcjudge(b, c, a)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }

  return 0;
}
