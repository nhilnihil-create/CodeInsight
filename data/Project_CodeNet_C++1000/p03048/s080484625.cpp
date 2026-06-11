#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int R, G, B, N; cin >> R >> G >> B >> N;
  
  int64_t ans = 0;
  
  for (int i = 0; i * R <= N; i++) {
    
    for (int j = 0; j * G + i * R <= N; j++) {
      
      if ((N - (i * R) - (j * G)) % B == 0) ans++;
      
    }
    
  }
  
  cout << ans << endl;
  
}