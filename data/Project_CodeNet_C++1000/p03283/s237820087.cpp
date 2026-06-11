#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  
  int x[510][510] = {0};
  int c[510][510] = {0};
  
  for (int i = 0; i < M; i++) {
    int L, R;
    cin >> L >> R;
    
    x[L][R]++;
    
  }
  
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      c[i][j] = c[i][j-1] + x[i][j];
    }
  }
  

  
  for (int i = 0; i < Q; i++) {
    int ans = 0;
    
    int p, q;
    cin >> p >> q;
    
    for (int j = p; j <= q; j++) {
      ans += c[j][q] - c[j][p-1];
    }
    
    cout << ans << endl;
    
    
  }
}