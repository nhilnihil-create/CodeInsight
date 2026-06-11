#include<bits/stdc++.h>
using namespace std ; 

int main() {
  string S ; 
  cin >> S ; 
  for(int i = 0 ; i < S.size() ; i++){
    if (S.at(i) == '1'){
      cout << 9  ; 
    }
    else if(S.at(i) == '9'){
      cout << 1 ;
    }
    
  }
  cout << endl ; 
}