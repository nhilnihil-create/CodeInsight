#include <bits/stdc++.h>
#define reg register
#define ll long long
#define ull unsigned long long
using namespace std;
const int MAXN = 1010;
const int MAXM = 50;
int X[MAXN], Y[MAXN], len[MAXM];
int n;
char s[MAXM];
void work() {
  scanf("%d", &n);
  for(reg int i = 1; i <= n; ++i) scanf("%d%d", &X[i], &Y[i]);
  int tmp = abs(X[1] + Y[1]) % 2;
  for(reg int i = 1; i <= n; ++i) {
    if(abs(X[i] + Y[i]) % 2 != tmp) {
      puts("-1");
      return;
    }
  }
  printf("%d\n", 32 - tmp);
  int tot = 0;
  len[++tot] = 1;
  printf("1");
  if(tmp) {
    for(reg int i = 1; i <= 30; ++i) printf(" %d", len[++tot] = (1 << i));
    puts("");
  } else {
    for(reg int i = 0; i <= 30; ++i) printf(" %d", len[++tot] = (1 << i));
    puts("");
  }
  for(reg int i = 1; i <= n; ++i) {
    ll nowx = 0, nowy = 0;
    for(reg int j = tot; j >= 1; j--) {
      ll nxtx = X[i] - nowx, nxty = Y[i] - nowy;
      if(abs(nxtx) > abs(nxty)) {
        if(nxtx > 0) nowx += len[j], s[j] = 'R';
        else nowx -= len[j], s[j] = 'L';
      } else {
        if(nxty > 0) nowy += len[j], s[j] = 'U';
        else nowy -= len[j], s[j] = 'D';
      }
    }
    printf("%s\n", s + 1);
  }
}
signed main() {
  int _ = 1;
  // scanf("%d", &_);
  while(_--) {
    work();
  }
  return 0;
}
