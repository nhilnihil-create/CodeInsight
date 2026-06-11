#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int N = S.size() ; 
  int cnt = 0 ; 
  int total = 0 ; 
  
  if(S.at(0) != 'A'){
    cout << "WA" << endl ; 
    return 0 ; 
  }
  
  for(int i = 2 ; i < N-1 ; i++){
    if(S.at(i) == 'C'){
      cnt++ ; 
    }
   
  }
  
  
  for(int i = 0 ; i< N ; i++){
     if(isupper(S.at(i))){
      total++ ; 
    }
  }
  
  if(cnt != 1){
    cout << "WA" << endl ; 
    return 0 ; 
  }  
  
  if(total > 2){
    cout << "WA" << endl ; 
    return 0 ; 
  } 
  
  
  cout << "AC" << endl ; 

  
}