#include<bits/stdc++.h>
using namespace std;

int main(){
  
  string S, T;
  cin >> S >> T;
  int i, j, Ns = S.size(), Nt = T.size();
  
  for(i = Ns - Nt; i >= 0; i--){
    
    bool flag = true;
    for(j = 0; j < Nt; j++){
      if(S[i + j] != T[j] && S[i + j] != '?'){
        flag = false;
        break;
      }
    }
    
    if(flag){
      for(j = 0; j < Nt; j++){
        S[i + j] = T[j];
      }

      for(j = 0; j < Ns; j++){
        if(S[j] == '?'){
          cout << 'a';
        }else{
          cout << S[j];
        }
      }
      return 0;
    }
  }
  cout << "UNRESTORABLE" << endl;
  return 0;
}