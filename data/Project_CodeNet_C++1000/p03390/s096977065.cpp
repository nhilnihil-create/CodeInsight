#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  for(int o = 1, x, y; o <= q; ++o) {
    scanf("%d%d", &x, &y);
    if(x == y) {
      printf("%d\n", 2 * (x - 1));
    } else {
      if(x > y) swap(x, y);
      ll pos = 1ll * x * y, gg = sqrtl(pos - 1);
      ll ans = 2 * gg - 1;
      if((pos - 1) / gg == gg) {
        ans--;
      }
      printf("%lld\n", ans);
    }
  }
  return 0;
}

/*
8
1 4
10 5
3 3
4 11
8 9
22 40
8 36
314159265 358979323

1
12
4
11
14
57
31
671644785

*/