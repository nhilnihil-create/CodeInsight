#include<bits/stdc++.h>
using namespace std ;

int main(){
  long long N , M , A ; 
  cin >> N >> M  ;
  
  A = (1900*M+100*(N-M))*pow(2,M) ; 
  cout << A << endl;
}