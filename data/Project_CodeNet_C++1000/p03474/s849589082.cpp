#include <bits/stdc++.h>
using namespace std;

int main(){
 int A, B;
 string S;
 
  cin >> A >> B;
  cout << endl;
  cin >> S;
  
  if( S[A] != '-' ) { cout << "No" << endl; return 0; }
  for(int i = 0; i < A + B; i++){
   if( i == (A) ) { continue; }
    if( S[i] == '-' ) { cout << "No" << endl; return 0; }
  }
  cout << "Yes" << endl;
  return 0;
}