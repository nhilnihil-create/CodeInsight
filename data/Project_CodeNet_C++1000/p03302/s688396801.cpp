#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  
  string ans = "x";
  if (a + b == 15) {
    ans = "+";
  }
  if (a * b == 15) {
    ans = "*";
  }

  cout << ans << '\n';

  return 0;
}
