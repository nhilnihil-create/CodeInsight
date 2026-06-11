#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  char c[N];
  for (int i = 0; i < N; i++) cin >> c[i];
  
  vector<int> s_W(N+1, 0), s_E(N+1, 0);
  
  for (int i = 0; i < N; i++) {
    if (c[i] == 'W') {
      s_W[i+1] = s_W[i] + 1;
      s_E[i+1] = s_E[i];
    }
    if (c[i] == 'E') {
      s_W[i+1] = s_W[i];
      s_E[i+1] = s_E[i] + 1;
    }
  }
  
  

  int ans = N;
  for (int i = 1; i < N+1; i++) {
    int x;
    x = s_W[i-1] - s_W[0] + s_E[N] - s_E[i];   

    if (x < ans) ans = x;
  }
  
  cout << ans << endl;
  
}