#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  bool yes = (a < b && a < c && c < b) || (a > b && a > c && c > b);
  if (yes)
    puts("Yes");
  else
    puts("No");
}