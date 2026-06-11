#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> A(1 << N);
  for (int i = 0; i < (1 << N); i++){
    cin >> A[i];
  }
  vector<pair<int, int>> B(1 << N);
  for (int i = 0; i < (1 << N); i++){
    B[i] = make_pair(A[i], 0);
  }
  for (int i = 0; i < N; i++){
    for (int j = 0; j < (1 << N); j++){
      if (j >> i & 1){
        int tmp1, tmp2;
        if (B[j].first > B[j - (1 << i)].first){
          tmp1 = B[j].first;
          tmp2 = max(B[j].second, B[j - (1 << i)].first);
        } else {
          tmp1 = B[j - (1 << i)].first;
          tmp2 = max(B[j - (1 << i)].second, B[j].first);
        }
        B[j] = make_pair(tmp1, tmp2);
      }
    }
  }
  vector<int> C(1 << N, 0);
  for (int i = 1; i < (1 << N); i++){
    C[i] = B[i].first + B[i].second;
  }
  for (int i = 2; i < (1 << N); i++){
    C[i] = max(C[i], C[i - 1]);
  }
  for (int i = 1; i < (1 << N); i++){
    cout << C[i] << endl;
  }
}