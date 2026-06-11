#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

string s, t;
bool bl;
bool ans = false;

int main() {
  cin >> s >> t;
  s += s;
  rep (i, t.size()) {
    bl = true;
    rep (j, t.size()) {
      if (s[i+j] != t[j]) bl = false;
    }
    if (bl) ans = true;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}
