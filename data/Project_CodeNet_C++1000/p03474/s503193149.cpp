#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  string S;
  cin >> A >> B >> S;
  for(int i = 0; i < A; i++){
    if(!(S.at(i) >= '0' && S.at(i) <= '9')){
      cout << "No" << endl;
      return 0;
    }
  }
  if(S.at(A) != '-'){
    cout << "No" << endl;
    return 0;
  }
  for(int i = A + 1; i < A + B + 1; i++){
    if(!(S.at(i) >= '0' && S.at(i) <= '9')){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
