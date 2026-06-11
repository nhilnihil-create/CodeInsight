#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  bool flag = true;
  rep(i, s.size()) {
    if (i == a)
      flag &= (s[i] == '-');
    else
      flag &= isdigit(s[i]);
  }
  cout << (flag ? "Yes" : "No") << endl;
  return 0;
}
