#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  int M;
  M = N;
  
  int sum;
  sum = 0;
  
  for (int i = 0; i < 8; i++) {
   sum += N % 10;
   N /= 10 ;
  }
    
   if ( M % sum == 0){
   cout << "Yes" << endl;
   }
  else  {
    cout << "No" << endl;
  }
}
