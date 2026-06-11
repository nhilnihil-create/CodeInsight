#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  bool ok = true;
  rep(i, s.size()) {
    if (i == a && s[i] != '-') ok = false;
    if (i != a && (s[i] < '0' || s[i] > '9')) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}