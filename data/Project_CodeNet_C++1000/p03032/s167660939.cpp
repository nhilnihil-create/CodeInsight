#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> V(N);
  for (int i = 0; i < N; i++) cin >> V.at(i);
  
  int ans = 0;
  for (int A = 0; A <= min(N, K); A++) {
    for (int B = 0; B <= min(N, K); B++) {
      if (A + B > min(N, K)) continue;
      int S = 0;
      priority_queue<int, vector<int>, greater<int>> Q;
      for (int i = 0; i < A; i++) {
        S += V.at(i);
        Q.push(V.at(i));
      }
      for (int i = 0; i < B; i++) {
        S += V.at(N - 1 - i);
        Q.push(V.at(N - 1 - i));
      }
      for (int i = 0; i < K - (A + B); i++) {
        if (Q.empty()) break;
        int p = Q.top();
        Q.pop();
        if (p < 0) S -= p;
        else break;
      }
      ans = max(ans, S);
    }
  }
  
  cout << ans << endl;
}