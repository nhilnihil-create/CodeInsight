#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K; cin >> N >> K; double ans = 0.0;
  
  for (int i = 1; i < N + 1; i++) {
    
    int tmp = i; int count = 0;
    
    while (true) {
      if (K <= tmp) break;
      tmp *= 2; count++;
    }
    
    int denominator = N * int(pow(2, count));
    
    ans += 1.0 / double(denominator);
    
  }
  
  cout << fixed << setprecision(10);
  
  cout << ans << endl;
  
}