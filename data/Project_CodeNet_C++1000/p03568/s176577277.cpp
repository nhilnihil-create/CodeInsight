#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int count = 0;
  
  for (int i = 0; i < N; i++) {
    
    int A; cin >> A;
    
    if (A % 2 == 0) count++;
    
  }
  
  int64_t ans = int64_t(pow(3, N)) - int64_t(pow(2, count));
  
  cout << ans << endl;
  
}