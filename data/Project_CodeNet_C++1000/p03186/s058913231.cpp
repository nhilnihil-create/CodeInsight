#include <bits/stdc++.h>

using namespace std;

#define foru(i, l, r) for (register int i = l; i <= r; i++)
#define ford(i, r, l) for (register int i = r; i >= l; i--)

int A, B, C, Ans;

int main() {
  scanf("%d%d%d", &A, &B, &C);
  if (B >= C) return printf("%d\n", B + C), 0;
  Ans += B << 1, C -= B, B -= B;
  printf("%d\n", Ans + min(A + 1, C));
  return 0;
}
