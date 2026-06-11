#include <stdio.h>

char s[5001], t[6];
int sl, tl;
int k, i, iM, j;
char c[6];
inline int strin() {
  i = 0;
  iM = sl - tl;
  while (i <= iM) {
    for (j = 0; j < tl; ++j) {
      if (s[i + j] != t[j]) goto continue_while;
    }
    return 1;
  continue_while:
    ++i;
  }
  return 0;
}
void solve() {
  if (!strin()) return;
  if (k == 0) {
    printf("%s\n", t);
    k = -1;
    return;
  }
  --k;
  ++tl;
  for (c[tl] = 'a'; c[tl] <= 'z'; ++c[tl]) {
    t[tl - 1] = c[tl];
    solve();
    if (k < 0) return;
  }
  --tl;
  t[tl] = 0;
}
int main() {
  scanf("%s", s);
  sl = 5000;
  while (sl - i > 1) {
    j = (sl + i) >> 1;
    if (s[j]) {
      i = j;
    } else {
      sl = j;
    }
  }
  scanf("%d", &k);
  solve();
}
