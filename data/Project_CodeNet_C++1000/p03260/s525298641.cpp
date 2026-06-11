#include <bits/stdc++.h>
using namespace std;

int main () {
  int a, b;
  cin >> a >> b;
  string ans = "No";
  for (int i = 1; i < 4; i++) {
    int n = a * b * i;
    if (n % 2 == 1) ans = "Yes";
  }
  cout << ans << endl;
  return 0;
}