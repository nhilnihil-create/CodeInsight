#include <bits/stdc++.h>
#define int long long
#define fo(i, n) for(int i = 1; i <= (n); i ++)
#define out(x) cerr << #x << " = " << x << "\n"
using namespace std;
// by piano
template<typename tp> inline void read(tp &x) {
  x = 0; char c = getchar(); bool f = 0;
  for(; c < '0' || c > '9'; f |= (c == '-'), c = getchar());
  for(; c >= '0' && c <= '9'; x = (x << 3) + (x << 1) + c - '0', c = getchar());
  if(f) x = -x;
}
int K;

inline int cal(int n) {
  return n < 10 ? n : cal(n / 10) + (n % 10);
}

main(void) {
  read(K);
  int r = 0, x = 1;
  for(; K --;) {
    for(; cal(r + x) * (r + x * 10) < cal(r + x * 10) * (r + x); x *= 10);
    cout << (r += x) << "\n";
  }
}
