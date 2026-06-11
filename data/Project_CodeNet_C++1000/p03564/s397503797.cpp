#include <bits/stdc++.h>
using namespace std;

int main() {

  int N,K,D;D=1;
  cin >> N >> K ;

   for (int i = 0 ; i < N ; i++){
     if ( D * 2 <= D + K ){
       D = D * 2;
     }
     else{
       D = D + K ;
     }
   }
  cout << D << endl;
}