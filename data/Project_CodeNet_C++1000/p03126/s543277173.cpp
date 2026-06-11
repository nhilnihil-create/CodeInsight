#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  int count = 0;
  int K,A;

   vector<vector<int>> data(N, vector<int>(M,0));
 
  for (int i = 0; i < N; i++) {
    cin >> K;
    for (int j = 0; j < K; j++) {
      cin >> A;
      data.at(i).at(A-1) = 1;
    }
  }
  
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      if (data.at(j).at(i) == 0){
        break;
      }
      else if (j == N - 1){
        count++;
      }
    }
  }
  cout << count << endl;
}