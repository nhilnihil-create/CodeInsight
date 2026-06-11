#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (100000)

using namespace std;

#define NUM_ELEM (1 << 17)
#define SIZE_BUF (2 * NUM_ELEM - 1)
#define INF (1000000000000000000L)

long buf[SIZE_BUF];

void st_init(const long *as, long n) {
  // copy array to the leaves
  for (int i = 0; i < NUM_ELEM; i++)
    buf[NUM_ELEM - 1 + i] = i < n ? as[i] : -INF;

  // calculate the inner nodes
  for (int i = NUM_ELEM - 2; i >= 0; i--) {
    const int chl = 2 * i + 1, chr = 2 * i + 2;
    buf[i] = max(buf[chl], buf[chr]);
  }
}

void st_update(long k, long e) {
  // update starting at the given node
  int i_cur = NUM_ELEM - 1 + k;
  buf[i_cur] = k;
  while (i_cur != 0) {
    const int i_nxt = (i_cur - 1) / 2;
    const int other = i_cur + (i_cur % 2 == 0 ? -1 : 1);
    buf[i_nxt] = buf[i_cur] <= buf[other] ? buf[i_cur] : buf[other];
    i_cur = i_nxt;
  }
}

long st_range_query_r(int b, int e, int cur, int curb, int cure) {
  // printf("%d, %d, %d, %d, %d\n", b, e, curb, cure, buf[cur]);
  if (e <= curb || b >= cure) {
    return -INF;
  } else if (b <= curb && e >= cure) {
    return buf[cur];
  } else {
    const int m = (curb + cure) / 2;
    const int chl = 2 * cur + 1, chr = 2 * cur + 2;
    return max(st_range_query_r(b, e, chl, curb, m),
               st_range_query_r(b, e, chr, m, cure));
  }
}

long st_range_query(int b, int e) {
  return st_range_query_r(b, e, 0, 0, NUM_ELEM);
}

int main(int argc, char *argv[]) {
  // read inputs
  long N, C, xs[MAX_N], vs[MAX_N];
  scanf("%ld %ld", &N, &C);
  for (int i = 0; i < N; i++) {
    scanf("%ld %ld", &xs[i], &vs[i]);
  }

  // calculate accumulated sums to use later
  long acc_clock_vs[MAX_N], acc_anticlock_vs[MAX_N];
  long net_clock_oneways[MAX_N], net_anticlock_oneways[MAX_N];
  long net_clock_bothways[MAX_N], net_anticlock_bothways[MAX_N];
  acc_clock_vs[0] = vs[0];
  for (int i = 1; i < N; i++) {
    acc_clock_vs[i] = acc_clock_vs[i - 1] + vs[i];
  }
  acc_anticlock_vs[N - 1] = vs[N - 1];
  for (int i = N - 2; i >= 0; i--) {
    acc_anticlock_vs[i] = acc_anticlock_vs[i + 1] + vs[i];
  }
  for (int i = 0; i < N; i++) {
    net_clock_oneways[i] = acc_clock_vs[i] - xs[i];
    net_anticlock_oneways[i] = acc_anticlock_vs[i] - (C - xs[i]);
    net_clock_bothways[i] = acc_clock_vs[i] - 2 * xs[i];
    net_anticlock_bothways[i] = acc_anticlock_vs[i] - 2 * (C - xs[i]);
  }

  // solve
  // pattern 1: walk clockwise and exit somewhere
  long ans1 = 0;
  for (int i = 0; i < N; i++) {
    ans1 = max(ans1, net_clock_oneways[i]);
  }

  // pattern 2: walk anticlockwise and exit somewhere
  long ans2 = 0;
  for (int i = 0; i < N; i++) {
    ans2 = max(ans2, net_anticlock_oneways[i]);
  }

  // pattern 3: walk clockwise, turn around, walk anticlockwise
  long ans3 = 0;
  st_init(net_anticlock_oneways, N);
  for (int i = 0; i < N - 1; i++) {
    ans3 = max(ans3, net_clock_bothways[i] + st_range_query(i + 1, N));
  }

  // pattern 4: walk anticlockwise, turn around, walk clockwise
  long ans4 = 0;
  st_init(net_clock_oneways, N);
  for (int i = 1; i < N; i++) {
    ans4 = max(ans4, net_anticlock_bothways[i] + st_range_query(0, i));
  }

  // print ans
  // printf("ans1 = %ld, ans2 = %ld, ans3 = %ld, ans4 = %ld\n", ans1, ans2, ans3,
  //        ans4);
  printf("%ld\n", max(0L, max(max(ans1, ans2), max(ans3, ans4))));

  return 0;
}
