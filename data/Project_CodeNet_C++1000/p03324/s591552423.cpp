#include <bits/stdc++.h>
using namespace std;

int main() {
  int D, N;
  cin >> D >> N;
  
  
  int MIN = 1;
  for (int i = 0; i < D; i++) {
    MIN *= 100;
  }
  
  int NEXT_MIN = MIN * 100;
  
  
  int count = 0;
  int ans = MIN;
  
  while (true) {  
    if (ans % MIN == 0 && ans % NEXT_MIN != 0) count++;
    if (count == N) {
      cout << ans << endl;
      return 0;
    }
    ans += MIN;
  }
}
