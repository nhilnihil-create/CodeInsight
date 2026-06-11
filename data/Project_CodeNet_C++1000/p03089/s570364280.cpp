#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> b(N);
  for (int i = 0; i < N; i++){
    cin >> b[i];
  }
  vector<int> ans(N, -1);
  bool ok = true;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N - i; j++){
      if (b[j] == j + 1){
        ans[i] = j;
      }
    }
    if (ans[i] == -1){
      ok = false;
      break;
    } else {
      b.erase(b.begin() + ans[i]);
    }
  }
  if (!ok){
    cout << -1 << endl;
  } else {
    for (int i = N - 1; i >= 0; i--){
      cout << ans[i] + 1 << endl;
    }
  }
}