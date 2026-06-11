#include<bits/stdc++.h>
using namespace std ;


int main(){
  int A , B ; 
  cin >> A >> B ; 
  
  int cnt = 0 ; 
  
  for(int i = A ; i <= B ; i++){
    int T = 0 ; 
    string S = to_string(i) ;
    for(int j = 0 ; j < S.size() ; j++){
      if(S.at(j) != S.at(S.size() - 1 - j )){
        T++ ; 
      }
    }
    
    if(T ==  0 ){
      cnt++ ; 
    }
         
    
  }
  
  cout << cnt << endl ; 
  
}