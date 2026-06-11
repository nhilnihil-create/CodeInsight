#include<bits/stdc++.h>
using namespace std ;

int main(){
  int A , B ; 
  cin >> A >> B ; 
  string S ;
  cin >> S ; 
  int cnt = 0 ; 
  if(S.at(A) == '-' && S.size() == A+B+1 ){
    for(int i = 0 ; i < S.size() ; i++){
      if(S.at(i) == '-') cnt++ ; 
    }
    
    if(cnt == 1){
      cout << "Yes" << endl ; 
      return 0 ; 
    }
  }
  
  cout << "No" << endl;
}