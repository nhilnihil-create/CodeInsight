#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, ma, mi, med;
  cin >> a >> b >> c;
  ma = max(max(a, b),c);
  mi = min(min(a, b),c);
  med = a + b + c - mi - ma;
  cout << ma * 10 + mi + med;
  return 0;
}