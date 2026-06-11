#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; cin >> S; int numZero = 0, numOne = 0, ans;
  
  for (int i = 0; i < S.size(); i++) {
    
    if (S.at(i) == '0') numZero++;
    
    else numOne++;
    
  }
  
  ans = min(numZero, numOne) * 2;
  
  cout << ans << endl;
  
}