#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A , B;
  cin >> A >> B ;
  int count = 0 ;
  for ( int a=1 ; a<10 ; a++ ) {
    for ( int b=0 ; b<10 ; b++ ){
      for ( int c=0 ; c<10 ; c++ ){
        int x=10000*a+1000*b+100*c+10*b+a; 
        if ( A <= x && x <= B){
        count +=1; 
        }
      }
    }
  }
  cout << count << endl ;
}

