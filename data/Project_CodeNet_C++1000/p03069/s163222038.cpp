#include <bits/stdc++.h>
using namespace std;
int INF = 1000000;
int main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> L(N + 1, 0);
  for (int i = 0; i < N; i++){
    if (S[i] == '#'){
      L[i + 1] = L[i] + 1;
    } else {
      L[i + 1] = L[i];
    }
  }
  vector<int> R(N + 1, 0);
  for (int i = N - 1; i >= 0; i--){
    if (S[i] == '.'){
      R[i] = R[i + 1] + 1;
    } else {
      R[i] = R[i + 1];
    }
  }
  int ans = INF;
  for (int i = 0; i <= N; i++){
    ans = min(ans, L[i] + R[i]);
  }
  cout << ans << endl;
}