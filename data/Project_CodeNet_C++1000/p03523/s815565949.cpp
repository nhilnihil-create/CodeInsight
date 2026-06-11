#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

int main() {
  string s;
  cin >> s;

  vector<char> a = {'K', 'I', 'H', 'B', 'R'};
  int t = 0, c = 0;
  bool check = true;
  for (int i = 0; i < s.size(); i ++) {
    if (t < 5 && s[i] == a[t]) {
      t ++, c = 0;
      continue;
    }
    if (s[i] == 'A') {
      if (c >= 1 || t == 1 || t == 2) {
        check = false;
        break;
      } else {
        c ++;
      }
    } else {
      check = false;
      break;
    }
  }

  if (check && t == 5) cout << "YES" << endl;
  else cout << "NO" << endl;
}