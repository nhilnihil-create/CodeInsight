#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ; 
  vector<string> W(N) ; 
  
  for(int i = 0 ; i < N ; i++ ){
    cin >> W.at(i) ; 
  }
  
  for(int i = 0 ; i < N ; i++){
    for(int j = i+1 ; j < N ; j++ ){
      if( W.at(i) == W.at(j)) {
        cout << "No" << endl ; return 0 ; 
      }
    }
  }
  
  for(int i = 0 ; i < N-1 ; i ++){
    if(W.at(i).back() != W.at(i+1).front() ){
      cout << "No" << endl ; return 0 ;
    }
  }
  
  cout << "Yes" << endl ;
  
}