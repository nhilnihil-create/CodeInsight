#include<bits/stdc++.h>
using namespace std ; 

int main() {
  string N ; 
  cin >> N ; 
  //for(int i = 0 ; i < 3 ; i++) cout << N.at(i) << endl ;
  
  if(N.at(0) >= N.at(1) && N.at(0) >= N.at(2) ){

    for(int i = 0 ; i < 3 ; i++){
     int a = N.at(0) - '0' ; 
     cout << a  ; 
    }
  }
   else{
     for(int i = 0 ; i < 3 ; i++){
       int a = N.at(0)  - '0'; 
       cout << a+1 ;
     }
  }
}