#include <bits/stdc++.h>
using namespace std;

int main() {
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    if (a > b)
      swap(a, b);
    long long low = 0, high = 2e9;
    while (low + 1 < high) {
      long long mid = (low + high) / 2;
      long long x, y;
      if (mid % 2 == 0)
        x = mid / 2, y = mid / 2 + 1;
      else
        x = y = mid / 2 + 1;
      if (x * y < a * b)
        low = mid;
      else
        high = mid;
    }
    printf("%lld\n", low - (a != b));
  }
  return 0;
}