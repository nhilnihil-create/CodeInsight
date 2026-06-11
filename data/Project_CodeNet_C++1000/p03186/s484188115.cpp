#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c;
  cin >> a >> b >> c;
  if (b >= c) cout << b + c << '\n';
  else if (a >= c - b) cout << b + c << '\n';
  else cout << 2 * b + a + 1 << '\n';
  return 0;
}
