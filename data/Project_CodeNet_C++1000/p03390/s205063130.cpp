#include <bits/stdc++.h>
using namespace std;
typedef long long int64;

int64 sqrt(int64 x) {
  int64 l = 1, r = 1e9;
  while (l < r) {
    int64 m = (l + r) / 2 + 1;
    if (m * m <= x) l = m;
    else r = m - 1;
  }
  return l;
}

int64 solve(int64 a, int64 b) {
  if (a == 1 && b == 1) return 0;
  int64 x = a * b - 1;
  int64 o = sqrt(x);
  int64 ans = 2 * o - (x / o == o);
  if (a <= o || b <= o) --ans;
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", solve(a, b));
  }
  return 0;
}
