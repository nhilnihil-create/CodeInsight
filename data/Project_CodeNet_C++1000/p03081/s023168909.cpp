#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, n, q, a = -1, b;
  scanf("%lld%lld", &n, &q);
  b = n;
  char s[n + 10], t[q][3], d[q][3];
  scanf("%s", s);
  for(i = 0; i < q; ++i) scanf("%s%s", t[i], d[i]);
  for(i = q - 1; i >= 0; --i) {
    if(d[i][0] == 'L') {
      if(t[i][0] == s[a + 1]) a++;
      if(t[i][0] == s[b]) b++;
    } else {
      if(a != -1 && t[i][0] == s[a]) a--;
      if(t[i][0] == s[b - 1]) b--;
    }
    if(b - a == 1) break;
  }
  printf("%lld", b - a - 1);
  return 0;
}