#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, C;
  cin >> N >> M >> C;
  int B[M];
  for (int i = 0; i < M; i++) cin >> B[i];
  
  int ans = 0;
  int A[M];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[j];
    }
    int sum = 0;
    
    for (int j = 0; j < M; j++) {
      sum += A[j] * B[j];
    }
//    cout << sum + C << endl;
    if (sum + C > 0) ans++;
  }
  
  cout << ans << endl;  
}

