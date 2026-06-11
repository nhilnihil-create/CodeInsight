#include <bits/stdc++.h>

using namespace std;

int main()
{
  int A[2002];
  int N, K, Q;
  
  scanf("%d %d %d", &N, &K, &Q);
  
  A[0] = A[N + 1] = 0;
  for (int i = 1; i <= N; i++) {
    scanf("%d", A + i);
  }
  
  int ans = 1000000000;
  for (int i = 1; i <= N; i++) {
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int, vector<int>, greater<int>> pq2;
    for (int j = 0; j <= N + 1; j++) {
      if (A[j] < A[i]) {
        while (pq.size() >= K) {
          pq2.push(pq.top());
          pq.pop();
        }
        pq = decltype(pq)();
      }
      else {
        pq.push(A[j]);
      }
    }
    if (pq2.size() >= Q) {
      for (int j = 0; j < Q - 1; j++) {
        pq2.pop();
      }
      ans = min(ans, pq2.top() - A[i]);
    }
  }
  
  printf("%d\n", ans);
  
  return 0;
}