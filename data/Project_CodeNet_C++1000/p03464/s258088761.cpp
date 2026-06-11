#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1: *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) {
    ans = ((ans << 2) + ans << 1) + (ch ^ 48);
    ch = gc();
  }
  return ans;
}
typedef long long ll;
typedef vector <int> poly;
#define pb push_back
#define rez resize
const int N = 5e5 + 5, inf = 0x3f3f3f3f;
int n, a[N];
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 1; i <= n; ++i) {
    a[i] = read();
  }
  ll x = 2, y = 2;
  for (ri i = n; i; --i) {
    if (x % a[i]) {
      x = (x / a[i] + 1) * a[i];
    }
    y = (y / a[i] + 1) * a[i] - 1;
  }
  if (x <= y) {
    cout << x << ' ' << y;
  } else {
    cout << -1;
  }
  return 0;
}