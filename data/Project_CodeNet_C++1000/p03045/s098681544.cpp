#include <stdio.h>
using namespace std;
typedef long long ll;

int main(void) {
  ll i, j, n, m, x, y, z, ans = 0, na, nb, ra, rb;
  scanf("%lld%lld", &n, &m);
  ll uf[n];
  bool flg[n];
  for(i = 0; i < n; ++i) uf[i] = i, flg[i] = false;
  for(i = 0; i < m; ++i) {
    scanf("%lld%lld%lld", &x, &y, &z);
    na = --x, nb = --y, ra = rb = 0;
    while(uf[na] != na) na = uf[na], ra++;
    while(uf[nb] != nb) nb = uf[nb], rb++;
    uf[x] = na, uf[y] = nb;
    if(ra < rb) uf[x] = nb, uf[na] = nb;
    else uf[y] = na, uf[nb] = na;
  }
  for(i = 0; i < n; ++i) {
    na = i;
    while(uf[na] != na) na = uf[na];
    uf[i] = na;
    flg[na] = true;
  }
  for(i = 0; i < n; ++i) ans += flg[i];
  printf("%lld", ans);
  return 0;
}