#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int k=0;
  
  int A1;
  cin >> A1;

    
    while (A1%2 == 0){
      A1 /= 2;
      k += 1;
    }  
  
  for ( int i=0; i<N-1; i++){
    int A;
    cin >> A;
    int j =0;
    
    while (A%2 == 0){
      A /= 2;
      j += 1;
    }
    if (j<k)
      k =j; 
  }
      
   cout << k << endl;
  }
