#include <bits/stdc++.h>
using namespace std;
long long INF = 1000000000000;
int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<int>> D(C, vector<int>(C));
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      cin >> D[i][j];
    }
  }
  vector<vector<int>> c(N, vector<int>(N));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  vector<vector<long long>> S(C, vector<long long>(3, 0));
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      for (int k = 0; k < C; k++){
        S[k][(i + j) % 3] += D[c[i][j]][k];
      }
    }
  }
  long long ans = INF;
  for (int i = 0; i < C; i++){
    for (int j = 0; j < C; j++){
      for (int k = 0; k < C; k++){
        if (i != j && j != k && k != i){
          ans = min(ans, S[i][0] + S[j][1] + S[k][2]);
        }
      }
    }
  }
  cout << ans << endl;
}