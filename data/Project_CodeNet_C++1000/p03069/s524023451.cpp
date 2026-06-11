#include <bits/stdc++.h>
using namespace std;

void chmin(int& a, int b) {
  if (a > b) a = b;
}
int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  
  vector<int> B(N+1, 0), W(N+2, 0);
  int Bcount = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '#') Bcount++;
    B[i+1] = Bcount;
  }
  

  
  int Wcount = 0;
  for (int i = N-1; i >= 0; i--) {
    if (S[i] == '.') Wcount++;
    W[i+1] = Wcount;
  } 
  

  int ans = 200000;
  for (int i = 0; i <= N; i++) {
    chmin(ans, B[i]+W[i+1]);
  }
  
  cout << ans << endl;
}