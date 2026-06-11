#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<string> A(N);
  
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
 
  int M;
  cin >> M;
  
  vector<string> B(M);
  
  for (int i = 0; i < M; i++) cin >> B.at(i);
  
  int ans = -100;
  
  for (int i = 0; i < N; i++) {
    int count = 0;
    for (int j = 0; j < N; j++) {
      if (A.at(i) == A.at(j)) count++;
    }
    for (int k = 0; k < M; k++){
      if (A.at(i) == B.at(k)) count--;
    }
    ans = max(ans,count);
  }
  if (ans < 0) {
    cout << 0 << endl;
  }
  else
    cout << ans << endl;
}
  