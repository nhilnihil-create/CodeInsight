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
  int S[N+1][N+1];
  dotimes(R, N+1)
    dotimes(L, N+1)
      S[R][L] = 0;
  dotimes(i, M) {
    int L = rint();
    int R = rint();
    S[R][L]++;
  }
  dotimes(R, N)
    dotimes(L, N)
      S[R+1][L+1] += S[R+1][L] + S[R][L+1] - S[R][L];
  dotimes(i, Q) {
    int p = rint() - 1;
    int q = rint();
    wint(S[q][q] + S[p][p] - S[q][p] - S[p][q]);
  }
  return 0;
}
