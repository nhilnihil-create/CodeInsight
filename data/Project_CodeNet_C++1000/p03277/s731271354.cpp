#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long LL;
const int MAXN = 100000;
const int INF = 0x3f3f3f3f;
using namespace std;
 
inline void enableFileIO() {
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
}
 
inline int read() {
  int x = 0, w = 1;
  char c = ' ';
  
  while (c < '0' || c > '9') {
    c = getchar();
    if (c == '-') w = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return x * w;
}
 
int ans, n, a[MAXN + 5], sum[MAXN + 5];
int mn, mx;
 
void init() {
//  enableFileIO();
  
  n = read();
  mn = INF;
  mx = -INF;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
}
 
struct BinaryIndexTree {
  int c[MAXN * 2 + 5];
  int lowbit(int x) {
    return x & (-x);
  }
  void init() {
    memset(c, 0, sizeof(c));
  }
  void update(int x) {
    for (; x <= 2 * n; x += lowbit(x)) ++c[x];
  }
  int query(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += c[x];
    return ret;
  }
}BIT;
 
int b[MAXN + 5];
 
inline bool chk(int mid) {
  BIT.init();
  memset(sum, 0, sizeof(sum));
  
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i] >= mid ? 1 : -1;
    sum[i] = sum[i - 1] + b[i];
  }
  
  LL ret = 0;
  BIT.update(0 + n);
  for (int i = 1; i <= n; ++i) {
    ret += BIT.query(sum[i] + n);
    BIT.update(sum[i] + n);
  }
  return ret >= 1LL * n * (n + 1) / 4;
}
 
int main() {
  init();
  
  int l = mn, r = mx;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (chk(mid)) {
      l = mid + 1;
      ans = mid;
    } else {
      r = mid - 1;
    }
  }
  
  printf("%d\n", ans);
  return 0;
}