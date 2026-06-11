#include <bits/stdc++.h>
using namespace std;

int main() {
  long X, Y;
  cin >> X >> Y;
  int ans = 1;
  while (X * 2 <= Y) X *= 2, ans++;
  cout << ans << "\n";
}