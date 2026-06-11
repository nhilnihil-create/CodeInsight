#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  if ((a & 1) && (b & 1)) {
    puts("Odd");
  } else {
    puts("Even");
  }

  return 0;
}
