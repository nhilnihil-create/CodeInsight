#include<bits/stdc++.h>
using namespace std ;

int main () {
  int line[3] ;
  for(int i = 0 ; i < 3 ; i++ ) cin >> line[i] ;
  if(line[2] == line[1] && line[1] == line[0] ) cout << "Yes" << endl ;
  else cout << "No" << endl ;
}