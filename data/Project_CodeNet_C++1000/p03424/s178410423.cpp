#include <bits/stdc++.h>
using namespace std;

int main() {
  int N ;
  cin >> N ;
  string S ;
  int y = 0 ;
  for ( int h = 0; h < N; h++ ){
    cin >> S;
   if ( S == "Y" ){
      y = y + 1;
    }
  }
  if ( y >= 1){
    cout << "Four" << endl;
  }else {
    cout << "Three" << endl;
  }
}