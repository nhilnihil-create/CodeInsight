#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int ans = 0;
  
  for (int i = 0; i < N; i++) {
    
    int a; cin >> a;
    
    int count = 0;
    
    while (true) {
      
      if (a % 2 == 0) {
        a /= 2;
        count++;
      }
      
      else break;
      
    }
    
    ans += count;
    
  }
  
  cout << ans << endl;
  
}