#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string A, B, C;
  cin >> N;
  cin >> A >> B >> C;
  int ans = 0;
  
  for(int i=0; i<N; i++) {
    ans += 2;
    if (A[i] == B[i])
      ans--;
    if (B[i] == C[i])
      ans--;
    if (A[i] == C[i])
      ans--;
    if (A[i] == B[i] && B[i] == C[i])
      ans++;
  }
  
  cout << ans << endl;
  
}