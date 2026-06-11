#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

long max_value(int k, const vector<int> &as, const vector<int> &bs) {
  const long N = as.size();
  long ret = 0;
  for (int n = 0; n < N; n++) {
    const int a = as[n], b = bs[n];
    if ((a & ~k) == 0) {
      ret += b;
    }
  }
  return ret;
}

// read editorial
int main(int argc, char *argv[]) {
  // read inputs
  int N, K;
  vector<int> as, bs;
  scanf("%d %d", &N, &K);
  for (int n = 0; n < N; n++) {
    int a, b;
    scanf("%d %d", &a, &b);
    as.push_back(a);
    bs.push_back(b);
  }

  // solve
  long ans = max_value(K, as, bs);
  for (int k = 0; k < 30; k++) {
    if (K & (1 << k)) {
      ans = max(ans, max_value(((K & ~(1 << k)) | ((1 << k) - 1)), as, bs));
    }
  }
  printf("%ld\n", ans);

  return 0;
}
