#include<bits/stdc++.h>
using namespace std ;

int main(){
  int A , B , C ; 
  cin >> A >> B >> C ; 
  int K  ;
  cin >> K ; 
  
  int N = max(A , max(B , C)) ; 
  cout << pow(2 , K) * N + min(A+B , min(A+C , B+C)) << endl  ; 
  
}