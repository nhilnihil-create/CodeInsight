#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc()) 
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const int N = 1010;
int px[N], py[N], n, t = -1, arr[N], acnt;
void doit(int tx,int ty) {
  if (t == 0) putchar('L');
  rrp (i, 30, 0) {
    if (abs(tx) > abs(ty)) {
      if (tx > 0) putchar('R'), tx -= 1 << i;
      else putchar('L'), tx += 1 << i;
    } else {
      if (ty > 0) putchar('U'), ty -= 1 << i;
      else putchar('D'), ty += 1 << i;
    }
  }
  puts("");
}
int main() {
  read(n);
  rep (i, 1, n) {
    read(px[i]), read(py[i]);
    int tmp = (px[i] + py[i]) % 2 == 0 ? 0 : 1;
    if (t == -1) t = tmp;
    else if (tmp != t) {
      puts("-1");
      return 0;
    }
  }
  if (t == 0) {
    arr[++ acnt] = 1;
    rep (i, 1, n) px[i] ++;
  }
  rep (i, 1, 31) arr[++ acnt] = 1 << (31 - i);
  printf("%d\n", acnt);
  rep (i, 1, acnt)
    printf("%d ", arr[i]);
  puts("");
  rep (i, 1, n) doit(px[i], py[i]);
  return 0;
}
