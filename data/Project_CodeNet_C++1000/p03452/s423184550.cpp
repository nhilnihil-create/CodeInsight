#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <vector>

#define MAX_N (100000)
#define MAX_M (200000)

using namespace std;

long dfs(const vector<vector<pair<long, long>>> &adj_lists, vector<long> &xs,
         vector<long> &us, long i, long x) {
  long res = 1;
  for (pair<long, long> p : adj_lists[i]) {
    const long j = p.first, d = p.second, y = x + d;
    if (us[j]) {
      // check that there is no mismatch
      if (xs[j] != y) {
        return 0;
      }
    } else {
      // determine the coordinates of node j
      xs[j] = y;
      us[j] = 1;
      if (!dfs(adj_lists, xs, us, j, y)) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  // read inputs
  long N, M, ls[MAX_M], rs[MAX_M], ds[MAX_M];
  scanf("%ld %ld", &N, &M);
  for (long i = 0; i < M; i++) {
    scanf("%ld %ld %ld", &ls[i], &rs[i], &ds[i]);
    ls[i]--;  // NOTE : modified input
    rs[i]--;  // NOTE : modified input
  }

  // create graph
  vector<vector<pair<long, long>>> adj_lists(N, vector<pair<long, long>>());
  for (long i = 0; i < M; i++) {
    long l = ls[i], r = rs[i], d = ds[i];
    adj_lists[l].push_back(make_pair(r, d));
    adj_lists[r].push_back(make_pair(l, -d));
  }

  // count number of incoming edges
  vector<long> cnt_edge_ins(N, 0);
  for (long i = 0; i < M; i++) {
    cnt_edge_ins[rs[i]]++;
  }

  // determine the coordinates of each node
  long isPossible = 1;
  vector<long> xs(N, 0), us(N, 0);
  for (long i = 0; i < N; i++) {
    if (!us[i]) {
      // start at node i
      xs[i] = 0;
      us[i] = 1;
      if (!dfs(adj_lists, xs, us, i, 0)) {
        isPossible = 0;
        break;
      }
    }
  }

  if (isPossible) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}