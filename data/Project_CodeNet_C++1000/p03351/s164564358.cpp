#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool ans = false;
  if (abs(a-c) <= d) ans = true;
  if (abs(a-b) <= d && abs(c-b) <= d) ans = true;
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}