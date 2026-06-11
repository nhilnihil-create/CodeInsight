#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define pb push_back
using namespace std;

namespace Header_Template {
  typedef long long li;
  template<class T>inline void read(T &x) {
    x = 0;
    T tmp = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') tmp = -1, c = getchar();
    while (c >= '0' && c <= '9')
      x = (x << 1) + (x << 3) + c - '0', c = getchar();
    x *= tmp;
  }
  template<class T>inline void Max(T &x, T y) {
    if (y > x) x = y;
  }
  template<class T>inline void Min(T &x, T y) {
    if (y < x) x = y;
  }
}
using namespace Header_Template;

const int N = 2e5 + 10;
int n, a[N];

int main(void) {
  read(n);
  for (int i = 1; i <= n; ++i) read(a[i]);
  sort(a + 1, a + 1 + n);
  int ansx = a[n], ansy;
  double tmp = 1.0 * ansx / 2.0, d = 1e16;
  for (int i = 1; i < n; ++i)
    if (fabs(tmp - a[i]) < d) {
      d = fabs(tmp - a[i]);
      ansy = a[i];
    }
  printf("%d %d\n", ansx, ansy);
  
  return 0;
}
