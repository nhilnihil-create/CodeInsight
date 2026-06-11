#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (200000)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, as[MAX_N], bs[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }
  for (int j = 0; j < N; j++) {
    scanf("%d", &bs[j]);
  }

  // solve
  int aks[MAX_N], bks[MAX_N];
  long ans = 0;
  for (int k = 0, pow_2_k = 1; k < 32; k++, pow_2_k *= 2) {
    // count the number of pairs (i, j) where kth LSB of as[i] + bs[i] is 1
    // only account for the bits up to the kth LSB
    const int mask = (~0u) >> (31 - k);
    // printf("k = %d, mask = %08x\n", k, mask);
    for (int i = 0; i < N; i++) {
      aks[i] = as[i] & mask;
      // printf("i = %d, as[i] = %08x, aks[i] = %08x\n", i, as[i], aks[i]);
    }
    for (int j = 0; j < N; j++) {
      bks[j] = bs[j] & mask;
      // printf("j = %d, bs[j] = %08x, bks[j] = %08x\n", j, bs[j], bks[j]);
    }

    // sort bks so that we can binary search
    sort(bks, bks + N);

    // count how many bks[j] satisfy
    //     2^k - aks[i] <= bks[j] < 2^(k+1) - aks[i]
    //     or
    //     2^(k+1) + 2^k - aks[i] <= bks[j] < 2^(k+1) + 2^(k+1) - aks[i]
    // this is the number of js where the kth LSB of as[i] + bs[j] is 1
    long cnt = 0;
    for (int i = 0; i < N; i++) {
      const int b1 = pow_2_k - aks[i];
      const int e1 = 2 * pow_2_k - aks[i];
      const int b2 = 2 * pow_2_k + pow_2_k - aks[i];
      const int e2 = 2 * pow_2_k + 2 * pow_2_k - aks[i];
      const int cnt1 =
          lower_bound(bks, bks + N, e1) - lower_bound(bks, bks + N, b1);
      const int cnt2 =
          lower_bound(bks, bks + N, e2) - lower_bound(bks, bks + N, b2);
      // printf(
      //     "i = %d, b1 = %d, e1 = %d, cnt1 = %d, b2 = %d, e2 = %d, cnt2 = %d\n",
      //     i, b1, e1, cnt1, b2, e2, cnt2);
      cnt += cnt1 + cnt2;
    }
    if (cnt % 2 == 1) {
      ans += pow_2_k;
    }
  }
  printf("%ld\n", ans);

  return 0;
}
