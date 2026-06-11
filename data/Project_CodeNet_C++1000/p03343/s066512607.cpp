#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <utility>

#define MAX_N (2000)
#define INF (1000000000)

using namespace std;

void move_small(set<pair<int, int>> &p1s, set<pair<int, int>> &p2s, int num) {
  for (int i = 0; i < num; i++) {
    pair<int, int> p = *p1s.begin();
    p2s.insert(p);
    p1s.erase(p);
  }
}

int main(int argc, char *argv[]) {
  // read inputs
  int N, K, Q, as[MAX_N];
  scanf("%d %d %d", &N, &K, &Q);
  for (int i = 0; i < N; i++) {
    scanf("%d", &as[i]);
  }

  // solve
  int ans = INF;
  for (int i = 0; i < N; i++) {
    const int y = as[i];

    // check if it possible to take y
    int num_around_y = 1;
    for (int j = i + 1; j < N && as[j] >= y; j++) {
      num_around_y++;
    }
    for (int j = i - 1; j >= 0 && as[j] >= y; j--) {
      num_around_y++;
    }
    if (num_around_y < K) {
      continue;
    }

    // check that more than Q elements >= y can be removed
    set<pair<int, int>> ps, pblocks;
    for (int j = 0; j < N; j++) {
      const int a = as[j];
      if (a >= y) {
        pblocks.insert(make_pair(a, j));
      } else {
        move_small(pblocks, ps,
                   pblocks.size() >= K ? pblocks.size() - K + 1 : 0);
        pblocks.clear();
      }
    }
    move_small(pblocks, ps, pblocks.size() >= K ? pblocks.size() - K + 1 : 0);
    if (ps.size() < Q) {
      continue;
    }

    // update
    int x = 0;
    for (int k = 0; k < Q; k++) {
      pair<int, int> p = *ps.begin();
      x = p.first;
      ps.erase(p);
    }
    ans = min(ans, x - y);
  }
  printf("%d\n", ans);

  return 0;
}
