#include <bits/stdc++.h>
using namespace std;

int main() {
  int ans = 0;
  char c;
  while (cin >> c) ans += (c == '+') ? 1 : -1;
  cout << ans << "\n";
}