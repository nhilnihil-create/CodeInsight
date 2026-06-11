#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  bool p = false;
  rep(bit, 1<<4) {
    string t;
    if (bit & 1<<0) t += "A";
    t += "KIH";
    if (bit & 1<<1) t += "A";
    t += "B";
    if (bit & 1<<2) t += "A";
    t += "R";
    if (bit & 1<<3) t += "A";
    if (s == t) p = true;
  }
  if (p) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}