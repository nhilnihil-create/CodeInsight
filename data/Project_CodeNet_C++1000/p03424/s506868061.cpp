#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ;
  cin >> N ; 
  bool ok = false ; 
  vector<char> S(N) ;  
  for(int i = 0 ; i < N ; i ++){
    cin >> S.at(i) ; 
    if(S.at(i) == 'Y') ok = true ; 
  }
  
  if(ok) cout << "Four" << endl;
  else cout << "Three" << endl;
  
}