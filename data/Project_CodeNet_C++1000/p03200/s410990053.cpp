#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; cin >> S;
  
  int64_t count = 0, ans = 0;
  
  for (int i = 0; i < S.size(); i++) {
    
    if (S.at(i) == 'W') {
      ans += i - count;
      count++;
    }
    
  }
  
  cout << ans << endl;
  
}