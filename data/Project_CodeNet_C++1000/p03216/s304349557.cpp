#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> M(N, 0);
  if (S[0] == 'M'){
    M[0] = 1;
  }
  for (int i = 1; i < N; i++){
    if (S[i] == 'M'){
      M[i] = M[i - 1] + 1;
    } else {
      M[i] = M[i - 1];
    }
  }
  vector<long long> M2(N, 0);
  for (int i = 1; i < N; i++){
    if (S[i] == 'C'){
      M2[i] = M2[i - 1] + M[i - 1];
    } else {
      M2[i] = M2[i - 1];
    }
  }
  vector<int> C(N, 0);
  if (S[0] == 'C'){
    C[0] = 1;
  }
  for (int i = 1; i < N; i++){
    if (S[i] == 'C'){
      C[i] = C[i - 1] + 1;
    } else {
      C[i] = C[i - 1];
    }
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++){
    int k;
    cin >> k;
    long long ans = 0;
    for (int j = 0; j < N; j++){
      if (S[j] == 'D'){
        int R = min(N - 1, j + k - 1);
        ans += M2[R] - M2[j];
        ans -= (long long)(C[R] - C[j]) * M[j];
      }
    }
    cout << ans << endl;
  }
}