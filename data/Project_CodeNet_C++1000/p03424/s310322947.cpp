#include <bits/stdc++.h>
using namespace std;

int main(void){
  int n, a = 0;
  cin >> n;
  
  for( int i = 0 ; i < n ; i++ ){
    string s;
    cin >> s;
    if( s == "Y" )  a = 1;
  }
  if( a == 0 ){
    cout << "Three" << endl;
  }
  else{
    cout << "Four" << endl;
  }
}