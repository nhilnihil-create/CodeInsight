#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 0;
  cin >> N;
  int A[N];
  bool isDivisible = true;
  int count = 0;
  
  for( int i = 0; i < N; ++i ){
    cin >> A[i];

    if( A[i] % 2 != 0 ){
      isDivisible = false;
    }
  }
  
  while( isDivisible ){
    for( int i = 0; i < N; ++i ){
      if( A[i] % 2 == 0 ){
        A[i] /= 2;
      }else{
        isDivisible = false;
        break;
      }
    }
    if( isDivisible == true ){
      ++count;
    }else{
      break;
    } 
  }
  cout << count << endl;
}
