#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

const int MaxN = 2000 + 5;
const int INF = 0x7F7F7F7F;

int N, K, Q, V;
int A[MaxN], D[MaxN];

void init() {
  scanf("%d %d %d", &N, &K, &Q);
  for (int i = 1; i <= N; ++i) {
    scanf("%d", &A[i]);
    D[i] = A[i];
  }
  std::sort(D + 1, D + 1 + N);
}

void solve() {
  int ans = INF;

  for (int x = 1; x <= N; ++x) {
    for (int i = 1; i <= N; ++i)
      if (A[i] < D[x]) A[i] = -1;
    std::priority_queue<int> pq, pq2;
    while (!pq.empty()) pq.pop();
    while (!pq2.empty()) pq2.pop();
    int num = 0, num2 = 0;
    for (int i = 1; i <= N; ++i) {
      if (A[i] == -1) {
        while (num >= K) {
          pq2.push(pq.top());
          pq.pop();
          num--; num2++;
        }
        while (!pq.empty()) pq.pop();
        num = 0;
      } else pq.push(-A[i]), num++;
    }
    while (num >= K) {
      pq2.push(pq.top());
      pq.pop();
      num--; num2++;
    }
    while (!pq.empty()) pq.pop();
    num = 0;

    int y = 0;
    if (num2 < Q) continue;
    for (int i = 1; i <= Q; ++i) {
      y = std::max(y, -pq2.top());
      pq2.pop();
    }
    ans = std::min(ans, y - D[x]);
  }

  printf("%d\n", ans);
}

int main() {
  init();
  solve();
  return 0;
}