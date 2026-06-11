#include <iostream>
#include<vector>
using namespace std;

int main(){
  int N, M, C;
  cin >> N >> M >> C;
  vector<int> B(M);
  for (int i = 0; i < M; i++) cin >> B[i];
  vector<vector<int>> A(N);
  for (int i = 0; i < N; i++) A[i].resize(M);
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < M; j++)
    {
      cin >> A[i][j];
    }
  }
  
  int ans = 0, feat;
  for (int i = 0; i < N; i++)
  {
    feat = C;
    for (int j = 0; j < M; j++)
    {
      feat += B[j] * A[i][j];
    }
    if (feat > 0) ans++;
  }
  cout << ans;
} 