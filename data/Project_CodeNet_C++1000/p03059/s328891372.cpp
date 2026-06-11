#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,T;
  cin >> A >> B >> T;
  
  int cookie = 0;
  //int time = 0;  

  for(int time = A ; time < T+1 ; time += A){
  	cookie += B;
  }
  
  cout << cookie << endl;
  
  return 0;
  
 }
