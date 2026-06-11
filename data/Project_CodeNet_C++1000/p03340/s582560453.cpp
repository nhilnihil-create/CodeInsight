#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++){
    cin >> A[i];
  }
  vector<long long> X(N + 1, 0);
  for (int i = 0; i < N; i++){
    X[i + 1] = X[i] ^ A[i];
  }
  vector<long long> S(N + 1, 0);
  for (int i = 0; i < N; i++){
    S[i + 1] = S[i] + A[i];
  }
  long long ans = 0;
  for (int i = 0; i < N; i++){
    int tv = i;
    int fv = N + 1;
    while (fv - tv > 1){
      int mv = (tv + fv) / 2;
      if ((X[mv] ^ X[i]) == S[mv] - S[i]){
        tv = mv;
      } else {
        fv = mv;
      }
    }
    ans += tv - i;
  }
  cout << ans << endl;
}