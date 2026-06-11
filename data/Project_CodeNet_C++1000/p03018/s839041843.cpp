#include <stdio.h>
typedef long long ll;

int main(void) {
  ll i, j, k, cnt = 0, ans = 0;
  char s[200010];
  scanf("%s", s);
  for(i = 0; s[i]; ++i) {
    if(s[i] == 'A') cnt++;
    else if(s[i] == 'B' && s[i + 1] == 'C') ans += cnt, ++i;
    else cnt = 0;
  }
  printf("%lld", ans);
  return 0;
}