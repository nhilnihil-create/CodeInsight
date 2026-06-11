#include <stdio.h>
#include <stdlib.h>
#include <vector>

#define MAX_N (100000L)
#define MAX_M (100000L)

using namespace std;

long is_bipartite(const vector<vector<long>> &adj_lists, vector<long> &cs,
                  long i) {
  for (long j : adj_lists[i]) {
    if (cs[j] < 0) {
      cs[j] = 1 - cs[i];
      if (!is_bipartite(adj_lists, cs, j)) {
        return 0;
      }
    } else {
      if (cs[j] == cs[i]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  // read inputs
  long N, M, as[MAX_M], bs[MAX_M];
  scanf("%ld %ld", &N, &M);
  for (long i = 0; i < M; i++) {
    scanf("%ld %ld", &as[i], &bs[i]);
    as[i]--;  // NOTE : modified input
    bs[i]--;  // NOTE : modified input
  }

  // create graph
  vector<vector<long>> adj_lists(N, vector<long>());
  for (long i = 0; i < M; i++) {
    const long a = as[i], b = bs[i];
    adj_lists[a].push_back(b);
    adj_lists[b].push_back(a);
  }

  // check if the graph is a bipartite graph
  vector<long> cs(N, -1);
  cs[0] = 0;
  const long b = is_bipartite(adj_lists, cs, 0);

  // print answer
  if (b) {
    long cnt0 = 0, cnt1 = 0;
    for (long i = 0; i < N; i++) {
      if (cs[i] == 0) {
        cnt0++;
      } else {
        cnt1++;
      }
    }
    printf("%ld\n", cnt0 * cnt1 - M);
  } else {
    printf("%ld\n", N * (N - 1) / 2 - M);
  }
}