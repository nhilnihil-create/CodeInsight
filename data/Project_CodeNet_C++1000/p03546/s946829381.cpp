#include <algorithm>
#include <cstdio>

#define int long long
#define macrocat_impl(a, b) a##b
#define macrocat(a, b) macrocat_impl(a, b)
#define dotimes_impl(i, n, x) for (int i = 0, x = n; i < x; i++)
#define dotimes(i, n) dotimes_impl(i, (n), macrocat(dotimes_n_, __COUNTER__))

using namespace std;

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

template<typename T>
inline int size(T container) {
  return static_cast<int>(container.size());
}

signed main() {
  int H = rint();
  int W = rint();
  int c[10][10];
  dotimes(i, 10)
    dotimes(j, 10)
      c[i][j] = rint();
  dotimes(k, 10)
    dotimes(i, 10)
      dotimes(j, 10)
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
  int r = 0;
  dotimes(i, H)
    dotimes(j, W) {
      int a = rint();
      if (a >= 0 && a != 1)
        r += c[a][1];
    }
  wint(r);
  return 0;
}
