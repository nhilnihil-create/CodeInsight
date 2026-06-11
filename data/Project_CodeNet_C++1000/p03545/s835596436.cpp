#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
  int X;
  cin >> X;
  int A = X / 1000;
  int B = X % 1000 / 100;
  int C = X % 100 / 10;
  int D = X % 10;
  if (A+B+C+D == 7) {
    printf("%d+%d+%d+%d=7", A, B, C, D);
  } else if (A+B+C-D == 7) {
    printf("%d+%d+%d-%d=7", A, B, C, D);
  } else if (A+B-C+D == 7) {
    printf("%d+%d-%d+%d=7", A, B, C, D);
  } else if (A+B-C-D == 7) {
    printf("%d+%d-%d-%d=7", A, B, C, D);
  } else if (A-B+C+D == 7) {
    printf("%d-%d+%d+%d=7", A, B, C, D);
  } else if (A-B+C-D == 7) {
    printf("%d-%d+%d-%d=7", A, B, C, D);
  } else if (A-B-C+D == 7) {
    printf("%d-%d-%d+%d=7", A, B, C, D);
  } else if (A-B-C-D == 7) {
    printf("%d-%d-%d-%d=7", A, B, C, D);
  }
  printf("\n");
  return 0;
}
