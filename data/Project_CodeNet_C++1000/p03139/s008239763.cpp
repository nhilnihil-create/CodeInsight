#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int main() {
  scanf("%d%d%d", &n, &x, &y);
  printf("%d %d\n", min(x, y), x + y <= n ? 0 : x + y - n);
}