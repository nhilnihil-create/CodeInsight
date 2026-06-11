#include <bits/stdc++.h>

using namespace std;

int main() {
  long long a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << (k % 2 == 0 ? a - b : b - a) << '\n';
  return 0;
}