#include <bits/stdc++.h>
using namespace std;
int main() {
  //input
  string S,T;
  cin >> S >> T;

  
  for (int i = S.length()-T.length(); i>=0; i--) {
    bool valid = true;
    for (int j = 0; j < T.length() && valid; j++) {
      if (S[i+j] != T[j] && S[i+j] != '?') {
        valid = false;
      }
    }
    
    if (valid) {
      for (int j = 0; j < T.length(); j++) {
        S[i+j] = T[j];
      }
      for (int j = 0; j < S.length(); j++) {
        if (S[j] == '?') {
          S[j] = 'a';
        }
      }
      cout << S <<endl;;
      return 0;
    }
  }

  
  cout << "UNRESTORABLE"<<endl;
  return 0;
}
