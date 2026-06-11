#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("%d\n", b + min(c, a + b + 1));
  return 0;
}
