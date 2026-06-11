#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int r = 0, b = 0, c = 0;
  rep(i, s.size()) {
    if (s[i] == '0') {
      if (b > 0) {
        c += 2;
        --b;
      } else {
        ++r;
      }
    } else {
      if (r > 0) {
        c += 2;
        --r;
      } else {
        ++b;
      }
    }
  }
  cout << c << endl;
  return 0;
}