#include <bits/stdc++.h>
using namespace std;

int main() {
 int N;
 cin >> N;
 
  for (int i =0; i < N; i++){
   string S;
   cin >> S;
   
    if( S != "Y" ){
     if( i<N-1 ){
     continue;
     }
     cout << "Three" << endl;
    }
   
    else if( S == "Y"){
     cout << "Four" << endl;
     break;
    }   
  } 
}