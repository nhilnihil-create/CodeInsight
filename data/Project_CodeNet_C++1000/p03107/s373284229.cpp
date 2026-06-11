#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  string s;
  cin >> s;
  ll one = 0, zc = 0;
  for (char x : s) {
    if (x == '0')
      ++zc;
    else
      ++one;
  }
  cout << 2 * min(one, zc) << endl;
}

int main() {
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}