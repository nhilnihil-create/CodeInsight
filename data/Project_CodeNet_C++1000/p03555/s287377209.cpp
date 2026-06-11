#include <bits/stdc++.h>
using namespace std;
int main() {
  string S,T; cin >> S >> T;
  
  if(S.at(0) == T.at(2) && S.at(1) == T.at(1) && S.at(2) == T.at(0)) {
    cout << "YES" << endl; 
  }
  else cout << "NO" << endl;    
}