#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int k = s.size();

  int win = 0;
  for (char c: s) {
    if (c == 'o') {
      win++;
    }
  }
  win += 15 - k;

  if (win >= 8) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}