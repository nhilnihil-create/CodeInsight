#include <bits/stdc++.h>
using namespace std;

int main(){
  string S, T;
  cin >> S >> T;
  
  int Slen = (int)(S.length()), Tlen = (int)(T.length());
  
  vector<string> kouho(0);
  for (int i = 0; i <= Slen - Tlen; i++){
    string ac = S;
    for (int j = 0; j < Tlen; j++){
      
      if (S.at(i + j) == '?' || S.at(i + j) == T.at(j)){
        ac.at(i + j) = T.at(j);
        
        if (j == Tlen - 1){
          for (int k = 0; k < Slen; k++){
            
            if (ac.at(k) == '?'){
              ac.at(k) = 'a';
            }
            
          }
          kouho.push_back(ac);
        }
        
        continue;
      }
      else{
        break;
      }
      
    }
  }
  
  if (kouho.size() > 0){
    sort(kouho.begin(), kouho.end());
  
    cout << kouho.at(0) << endl;
  }
  else{
    cout << "UNRESTORABLE" << endl;
  }
  
}