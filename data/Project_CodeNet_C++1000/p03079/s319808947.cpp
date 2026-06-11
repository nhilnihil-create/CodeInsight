#include <bits/stdc++.h>
const char nl = '\n';
using namespace std;
using ll = long long;
using ld = long double;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int a, b, c; cin >> a >> b >> c;
  puts((a == b && b == c) ? "Yes" : "No");
  return 0;
}
