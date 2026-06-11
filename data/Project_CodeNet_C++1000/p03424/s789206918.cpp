#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string b = "R";
  string a;
  cin >> N;
    
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
      b = "Y";
       break;
     }
    
   }
    if ( b == "Y" ){
      cout << "Four" << endl;
    }
    if ( b == "R"){
    cout << "Three" << endl;
    }
}