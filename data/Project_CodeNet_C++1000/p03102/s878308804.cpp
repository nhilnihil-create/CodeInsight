#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,C;
  int cnt = 0;
  cin >> N >> M >> C;
  vector<int> B(M);
  vector<vector<int>> A(N, vector<int>(M));
  vector<int> sum(N);
  
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  
  for (int j = 0; j < N; j++) {
    for (int i = 0; i < M; i++) {
      cin >> A[j][i];
      sum[j] += B[i]*A[j][i];
    }
    sum[j] += C;
    if (sum[j] > 0) {
      cnt += 1;
    }
  }
  cout << cnt << endl;
}