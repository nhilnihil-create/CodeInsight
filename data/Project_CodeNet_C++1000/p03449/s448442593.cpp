#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<int>> A(2, vector<int>(N));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    } 
  }
  int sum = 0, ans = 0;
  for (int i = 0; i < N; i++) {
    for (int k = 0; k <= i; k++) {
      sum += A[0][k];
      // cout << sum << endl;
    }
    for (int j = N - (N - i); j < N; j++) {
      sum += A[1][j];
      // cout << sum << endl;
    } 
    cout << endl;
    if (sum > ans) ans = sum;
    sum = 0;
  }
  cout << ans << endl;
}