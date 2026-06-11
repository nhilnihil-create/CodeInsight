#include <cstdio>
#define YES { puts("Yes"); return; }
#define NO { puts("No"); return; }

int T;
long long K, X0, XM, N;

inline long long gcd(long long a, long long b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

inline void solve() {
  if (X0 < K) NO
  if (X0 < XM && K > N) NO
  if (X0 < XM && K == N) YES
  long long g = gcd(K, N);
  long long t = (X0 - XM) / g;
  if (X0 < XM) t = (X0 - XM + 1) / g - 1;
  long long mn = X0 - t * g;
//  printf("mn = %lld\n", mn);
  if (K >= XM) {
    if (mn - K + N < K) NO
    else if (mn >= K) YES
    else NO
  } else {
    if (K <= N) YES
    else if (mn - K + N >= XM) YES
    else NO
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%lld %lld %lld %lld", &X0, &K, &XM, &N);
    XM++;
    solve();
  }
  return 0;
}