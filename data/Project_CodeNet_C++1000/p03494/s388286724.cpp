#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ;
  int c = 100;
  int d;
  for ( int i=0 ; i < N; i++ ) {
    int x; 
    cin >> x ;
    if (x%2 != 0){
      c=0;
        break ;
    }else if ( x%2 == 0){
   for ( int j=x ,y=0; j%2 == 0 ; ){
     y=y+1;
     j=j/2;
       d = min (y,c) ;
   }
    }
    c=min(d,c);
  }
  cout << c << endl ;
}

