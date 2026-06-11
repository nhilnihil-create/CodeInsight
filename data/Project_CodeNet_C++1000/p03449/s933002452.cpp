#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<vector<int>> A(2, vector<int>(N));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> A[i][j];
    }
  }
  
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    int res = 0;
    for (int j = 0; j <= i; ++j) {
      res += A[0][j];
    }
    for (int j = i; j < N; ++j) {
      res += A[1][j];
    }
    ans = max(ans, res);
  }
  
  cout << ans << endl;
}
