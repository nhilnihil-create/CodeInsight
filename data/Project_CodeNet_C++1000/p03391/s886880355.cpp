#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int mn = 2'000'000'000;
  long long tot = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    tot += x;
    if (x > y) {
      mn = min(mn, y);
    }
  }
  if (mn == 2'000'000'000) {
    puts("0");
  } else {
    printf("%lld\n", tot - mn);
  }
}
