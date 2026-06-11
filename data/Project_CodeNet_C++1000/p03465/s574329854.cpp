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
bitset <4000001> S;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  S[0] = 1;
  for (ri tt = read(); tt; --tt) {
    S |= S << read();
  }
  S[0] = 0;
  int t = (S.count() + 1) / 2, ct = 0;
  for (ri i = 1; i <= 4000000; ++i) {
    if (S[i]) {
      ++ct;
    }
    if (ct == t) {
      cout << i;
      return 0;
    }
  }
  return 0;
}