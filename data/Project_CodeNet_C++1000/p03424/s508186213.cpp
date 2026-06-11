#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string b;
  string a;
  cin >> N;
  for (int i=0;i < 1;i++) {
   
    
   for (int i=0;i < N;i++){
     cin >> a;
     if ( a == "P" ){
       continue;
     } 
     if ( a == "W" ){
       continue;
     }
     if ( a == "G" ){
       continue;
     }
     if ( a == "Y" ){
       cout << "Four" << endl;
      b = "Y";
       break;
     }
    
   }
    if ( b == "Y" ){
      break;
    }
    
    cout << "Three" << endl;
  }
}
