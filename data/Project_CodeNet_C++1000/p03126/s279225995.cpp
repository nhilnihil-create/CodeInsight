#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  vector<int> memo(M);
  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int A;
      cin >> A;
      memo.at(A - 1)++;
    }
  }
  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (memo.at(i) == N) {
      ans++;
    }
  }
  cout << ans << endl;
}