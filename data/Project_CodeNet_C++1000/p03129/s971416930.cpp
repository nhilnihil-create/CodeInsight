#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  if (k * 2 - 1 <= n) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}
