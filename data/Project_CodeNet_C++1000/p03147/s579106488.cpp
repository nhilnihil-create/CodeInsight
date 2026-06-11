#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int ans = 0;
  
  vector<int> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  for (int i = 0; i < 101; i++) {
    
    int count = 0;
    
    for (int j = 0; j < N; j++) {
      
      if (0 < vec[j]) count++;
      
      else {
        if (0 < count) ans++;
        count = 0;
      }
      
      vec[j]--;
      
    }
    
    if (0 < count) ans++;
    
  }
  
  cout << ans << endl;
  
}