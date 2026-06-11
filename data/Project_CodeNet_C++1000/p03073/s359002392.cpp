#include<bits/stdc++.h>
using namespace std ;

int main(){
  string S ; 
  cin >> S ; 
  int N = S.size() ; 
  vector<char> A(N) , B(N) ; 
  int cntA = 0 , cntB = 0  ; 
  
  
  for(int i = 0 ; i < N ; i++){
    if(i % 2 == 0 ){
      A.at(i) = '0' ; 
      B.at(i) = '1' ; 
    }
    else{
      A.at(i) = '1' ; 
      B.at(i) = '0' ;       
    }
    
  }
  
  for(int i = 0 ; i < N ;i++){
    if(S.at(i) == A.at(i) && S.at(i) != B.at(i)){
      cntA++ ; 
    }
    else if(S.at(i) == B.at(i) && S.at(i) != A.at(i)){
      cntB++ ; 
    }
    
  }

  cout << N - max(cntA , cntB) << endl ; 
  
}

