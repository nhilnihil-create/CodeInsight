#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N ;
  int n = N ;
  int c = 0;
  for ( int i=0 ; n > 0 ; i++ ) {
    int l ; 
    l = n%10 ;
    c += l ;
    n = (n-l)/10;
  }
  cout << (N % c ==0 ? "Yes" : "No" ) << endl;
}

