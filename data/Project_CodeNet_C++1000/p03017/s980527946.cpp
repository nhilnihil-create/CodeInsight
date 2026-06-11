#include <bits/stdc++.h>
using namespace std;

int main () {
  int N,A,B,C,D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  
  for (int i = A; i < max(C,D); i++) {
    if (S.at(i) == '#' && S.at(i-1) == '#'){
      cout << "No" << endl;
      return 0;
    }
  }
  
  if (C < D){
    cout << "Yes" << endl;
    return 0;
  }
  else {
    for (int i = B-1; i < D; i++) {
      if (S.at(i) == '.' && S.at(i-1) == '.' && S.at(i+1) == '.'){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
    
  