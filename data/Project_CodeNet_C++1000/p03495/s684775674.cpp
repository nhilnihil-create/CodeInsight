#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  
  vector<int> B(N + 10, 0);
  for (int i = 0; i < N; i++) B.at(A.at(i))++;
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  
  int ans = 0;
  for (int i = 0; i < N + 10; i++){
    if (B.at(i) == 0){
      cout << ans << endl;
      break;
    }
    else if (i < K) continue;
    else ans += B.at(i);
  }
    
}
