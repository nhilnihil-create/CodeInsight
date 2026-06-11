#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
  string s;
  cin >> s;
  int one = 0;
  int zero = 0;

  rep(i, s.size()) {
    if (s[i] == '1') one++;
    else zero++;
  }

  cout << min(one, zero) * 2 << endl;
}
