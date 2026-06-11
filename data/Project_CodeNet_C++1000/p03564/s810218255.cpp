#include <bits/stdc++.h>
using namespace std;

int main( ){
  int N;
  int K;
  int x;
  x = 1;
  cin >> N >> K;
  
  for ( int i = 1; i <= N ; i++){
    if( x*2-x > K){
      
      x += K;
      continue;
    }
    
    else {
      
      x *= 2;
      continue;
    }
  }
  cout << x << endl;
}