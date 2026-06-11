#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s ;
  cin >> s;
  bool ans = true ;
  for ( int i=0 ; i<a ; i++){
    if (s.at(i)=='-'){
      ans = false ;
      continue ;
    }
  }
    if ( s.at(a) != '-'){
      ans = false ;
    }
     for ( int i=a+1 ; i<a+1+b ; i++){
    if (s.at(i)=='-'){
      ans = false ;
    }
     }
      cout << ( ans ? "Yes" : "No")   << endl;
    
}