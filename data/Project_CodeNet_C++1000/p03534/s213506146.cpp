#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int c[3];
  memset(c, 0, sizeof(c));
  for (int i = 0; i < s.length(); ++i) {
    ++c[s[i] - 'a'];
  }
  sort(c, c + 3);
  cout << (c[2] <= c[0] + 1 ? "YES" : "NO") << endl;
}