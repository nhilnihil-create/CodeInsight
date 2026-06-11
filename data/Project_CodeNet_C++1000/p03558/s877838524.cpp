#include <bits/stdc++.h>
using namespace std;

#define MAXK 100000
#define INF (1<<30)
int d[MAXK];

int main() {
  int K; scanf("%d", &K);
  for(int i = 0; i < K; ++i) d[i] = INF;
  deque<int> deq = {1}; d[1] = 1;
  while(!deq.empty()) {
    int v = deq.front(); deq.pop_front();
    if(v == 0) break;
    int w = (v + 1) % K, u = (v * 10) % K;
    if(d[v] + 1 < d[w]) {
      d[w] = d[v] + 1; deq.push_back(w);
    }
    if(d[v] < d[u]) {
      d[u] = d[v]; deq.push_front(u);
    }
  }
  printf("%d\n", d[0]);
  return 0;
}
