#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, k, h, w, n, r, c, now;
  scanf("%lld%lld%lld%lld%lld", &h, &w, &n, &r, &c);
  char s[n + 10], t[n + 10], d[5] = "RLDU", dr[5] ="LRUD";
  ll f[4] = {w + 1 - c, c, h + 1 - r, r}, fr[4] = {c, w + 1 - c, r, h + 1 - r};
  bool flg[n];
  for(i = 0; i < n; ++i) flg[i] = false;
  scanf("%s%s", s, t);
  for(i = 0; i < 4; ++i) {
    priority_queue<ll> q;
    now = f[i];
    for(j = 0; j < n; ++j) {
      if(s[j] == d[i]) now--;
      if(!now) {
        if(q.empty()) {
          printf("NO");
          return 0;
        }
        flg[q.top()] = true;
        q.pop();
        now++;
      }
      if(t[j] == dr[i]) q.push(j);
    }
    now = fr[i];
    for(j = 0; j < n; ++j) {
      if(s[j] == d[i]) now++;
      if(t[j] == dr[i] && flg[j]) now--;
      if(!now) {
        printf("NO");
        return 0;
      }
    }
  }
  printf("YES");
  return 0;
}