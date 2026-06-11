#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, a, count = 0, ans = 9999;
  cin >> N;

  for(int i = 0; i < N; i++) {
  
    cin >> a;
    count = 0;
    
    for(int j = 0; j <= count + 1; j++) {
      
      if(a % 2 == 0) {
        count += 1;
        a /= 2;
      }
      
      else {
        break;
      }
      
    }
    
    if(count < ans) {
      ans = count;
    }
      
  }
 
  cout << ans << endl;
  
}