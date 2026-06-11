#include <bits/stdc++.h>
using namespace std;

int main() {
  int n1, n2, n3, n4;
  cin >> n1 >> n2 >> n3 >> n4;

  array<bool, 10> a;
  a[n1] = a[n2] = a[n3] = a[n4] = true;

  if (a[1] && a[9] && a[7] && a[4])
    puts("YES");
  else
    puts("NO");
}