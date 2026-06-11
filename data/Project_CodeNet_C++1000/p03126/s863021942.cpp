#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
  int a[M] = {0};

  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    for (int j = 0; j < K; j++) {
      int x;
      cin >> x;
      a[x-1]++;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < M; i++) {
    if (a[i] == N)
      ans++;
  }
  
  cout << ans << endl;
  
}