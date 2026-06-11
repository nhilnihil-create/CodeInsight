#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B, C, D , b, c ;
   cin >> N ;
 A = N / 1000 ;
 B = N - 1000 * A ;
 b = B /100 ;
 C = B - b * 100 ;
 c = C / 10 ;
 D = C - c * 10 ;
  if ( (A == b && b == c ) || (b == c && c == D) ) {
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}