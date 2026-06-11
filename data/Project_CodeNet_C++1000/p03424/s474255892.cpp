#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S, T;
  
  for(int i = 0; i < N; i++){
    
    cin >> S;
    
    if(S == "Y"){
     T = "Four";
     break;
   }
    else{
     T = "Three";
   }
  }
    cout << T << endl;
}
