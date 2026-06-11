#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
  int N;
  scanf("%d", &N);
  int A[N];
  long long ans = 0;
  for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
  if (A[0] != 0) {
    printf("-1");
    return 0;
  }
  for (int i = 1; i < N; ++i) {
    if (A[i] - A[i - 1] > 1) {
      printf("-1");
      return 0;
    } else if (A[i] <= A[i - 1]) ans += A[i];
    else ++ans;
  }
  printf("%lld", ans);
  return 0;
}