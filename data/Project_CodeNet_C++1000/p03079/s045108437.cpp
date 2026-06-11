#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  bool ok = a == b && b == c;
  if (ok)
    puts("Yes");
  else
    puts("No");
}