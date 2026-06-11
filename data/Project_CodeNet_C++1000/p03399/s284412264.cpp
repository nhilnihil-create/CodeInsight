#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  int e, f;
  
  if ( a >= b){
    e = b;
  }
  
  if ( b > a){
    e = a;
  }
  
  if ( c >= d){
    f = d;
  }
  
  if ( d > c){
    f = c;
  }
  
  cout << e + f << endl;

}