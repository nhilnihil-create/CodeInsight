#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++){
    cin >> S[i];
  }
  int ans = 0;
  for (int i = 0; i < N; i++){
    vector<string> T(N);
    for (int j = 0; j < N; j++){
      T[j] = S[(i + j) % N];
    }
    bool ok = true;
    for (int j = 0; j < N; j++){
      for (int k = 0; k < N; k++){
        if (T[j][k] != T[k][j]){
          ok = false;
        }
      }
    }
    if (ok){
      ans += N;
    }
  }
  cout << ans << endl;
}