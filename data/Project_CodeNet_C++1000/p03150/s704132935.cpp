#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S; cin >> S; string title = "keyence";
  
  int N = S.size(), M = title.size(); bool flag = false;
  
  for (int i = 0; i < M + 1; i++) {
    
    string leftSide = S.substr(0, i);
    string rightSide = S.substr(N - M + i, M - i);
    
    if (leftSide + rightSide == title) flag = true;
    
  }
  
  if (flag) cout << "YES" << endl;
  
  else cout << "NO" << endl;
  
}