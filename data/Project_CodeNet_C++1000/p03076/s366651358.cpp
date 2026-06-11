#include<bits/stdc++.h>
using namespace std ; 
const int inf = 1012345678;

int main(){
  int N = 5 ;  
  vector<int> A(N) ;  
  
  for(int i = 0 ; i < N ; i++){
    cin >> A.at(i) ;
  }
  
  vector<int> P = {0 , 1 , 2 , 3 , 4 } ; 
  int final_answer = inf ; 
  
do { 
  int ans= 0 ; 
  
  for(int i = 0 ; i < N ; i++){
    while( ans% 10 != 0 ) ans++ ; 
    ans += A.at(P.at(i)) ; 
  }
  
  final_answer = min(final_answer , ans) ;
} while (next_permutation(P.begin() , P.end())) ; 
  
  cout << final_answer << endl ; 
      
  
}