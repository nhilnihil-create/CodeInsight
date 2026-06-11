#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  string S;
  
  cin >> A >> B;
  cin >> S;
  if (S.size() == A + B + 1 && S.at(A) == '-'){
    for(int i = 0; i < S.size(); i++){
        if (i != A && S.at(i) == '-'){
          cout << "No" << endl;
          exit(0);
        }
    }
  }
  else {
    cout << "No" << endl;
    exit(0);
  }
  
  cout << "Yes" << endl;
  
}
