#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, A, B;
  cin >> N >> A >> B;
  
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          if (1000 * i + 100 * j + 10 * k + l > N) break;
          
          if (i + j + k + l >= A && i + j + k + l <= B) {
            ans += 1000 * i + 100 * j + 10 * k + l;
          }
        }
      }
    }
  }
  
  if (A == 1 && N == 10000) ans += 10000;
  cout << ans << endl;
  
  
}