#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string A;
  
  cin >> N;

  for(int i = 0; i < N; i++){
    cin >> A;
        
    if( i+1 < N && A != "Y"){

      continue;
    } 
    
    else if( i+1 == N && A != "Y"){
      cout << "Three" << endl;
      break;
    } 
    
    else {
      cout << "Four" << endl;
      break;
    }
  }

}
