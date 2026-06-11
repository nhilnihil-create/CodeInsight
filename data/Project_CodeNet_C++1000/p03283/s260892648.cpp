#include <cstdio>

#define int long long
#define dotimes(i, n) for (int i = 0; i < (n); i++)

using namespace std;

int rint() {
  int n;
  scanf("%lld", &n);
  return n;
}

void wint(int n) {
  printf("%lld\n", n);
}

signed main() {
  int N = rint();
  int M = rint();
  int Q = rint();
  int S[N][N];
  dotimes(R, N)
    dotimes(L, N)
      S[R][L] = 0;
  dotimes(i, M) {
    int L = rint() - 1;
    int R = rint() - 1;
    S[R][L]++;
  }
  dotimes(R, N)
    dotimes(i, R) {
      int L = R - i;
      S[R][L-1] += S[R][L];
    }
  dotimes(i, Q) {
    int p = rint() - 1;
    int q = rint() - 1;
    int r = 0;
    for (int R = p; R <= q; R++)
      r += S[R][p];
    wint(r);
  }
  return 0;
}
