#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A = 0;
  int B = 0;
  int C = 0;
  int N;
  cin >> N;

  for(int i = 0; i < N; i++){
  	string S;
  	cin >> S;
    if(A >= 1 && B >= 1 && C >= 1){
    if(S == "Y"){
     cout << "Four" << endl;
     break;
    
   }
    else if(i == N -1 && S !="Y"){
     cout << "Three" << endl;
    break;
    }
    }
   else if(S == "W"){
      A++; 
  }
    else if( S == "P"){
      B++;
  }
    else if( S == "G"){
      C++;
  }
          
       }
    }
  
