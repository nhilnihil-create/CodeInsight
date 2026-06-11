#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  string s; cin >> s;
  int r = 0, b = 0;
  for (char c : s) r += (c == 'R'), b += (c == 'B');
  puts(r > b ? "Yes" : "No");
  return 0;
}
