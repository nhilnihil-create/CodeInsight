#include<bits/stdc++.h>
using namespace std ;

int main(){
  int N ; 
  cin >> N ;
  vector<int> A(N+2); 
 
  long long S = 0 ; 
  A.at(0) = 0 ; 
  A.at(N+1) = 0 ; 
  for(int i = 1 ; i < N+1 ; i++){
    cin >> A.at(i) ;
  }
  


  for(int i = 1 ; i < N+2 ; i++){
    S += abs(A.at(i)-A.at(i-1)) ; 
  }
  
  for(int i =1 ; i < N+1 ; i++){
    cout << S + abs(A.at(i+1)-A.at(i-1))-abs(A.at(i-1)-A.at(i))-abs(A.at(i)-A.at(i+1)) <<endl ; 
  }
}