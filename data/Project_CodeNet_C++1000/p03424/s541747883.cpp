#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  string S;
  
  cin >> N;
  
  for (int i=0; i<N; i++){
    
    cin >> S;
    
    if (i < N  && S == "Y"){
     cout << "Four" << endl;
     break;
    }
    
    else if (i == N-1){
      
      if ( S == "Y"){
       cout << "Fore" << endl;
      }

      else{
       cout << "Three" << endl;
      }
     
    }
    
  }
  
  
  
  
}
