#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<bool> like(M, false);
  vector<bool> every(M, true);
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for(int j = 0; j < K; j++) {
      int A;
      cin >> A;
      like[A - 1] = true;
    }
    for(int k = 0; k < M; k++) {
      if(like[k] == false) {
        every[k] = false;
      }
      like[k] = false;
    }
  }
  int ans = 0;
  for(int i = 0; i < M; i++) {
    if(every[i]) {
      ans++;
    }
  }
  cout << ans << endl;
}