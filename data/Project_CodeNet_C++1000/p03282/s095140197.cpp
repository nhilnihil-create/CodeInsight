#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; int64_t K; cin >> S >> K;
  
  int position = -1, ans = 1; K--;
  
  for (int i = 0; i < S.size(); i++) {
    
    string tmp = S.substr(i, 1);
    
    if (tmp != "1") {
      
      position = i; ans = stoi(tmp); break;
      
    }
    
  }
    
  if (K < position || position == -1) cout << 1 << endl;
  
  else cout << ans << endl;
  
}