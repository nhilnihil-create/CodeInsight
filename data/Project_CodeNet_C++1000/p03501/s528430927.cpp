#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  int c;
  int d;
  int e;
  cin >> a >> b >> c;
  d = a * b;
  if(d != c){
    if(d < c){
      cout << d << endl;
    }
    else{
      cout << c << endl;
    }
  }
  else if(d == c){
    cout << d << endl;
  }
  //cout << d << endl;
  //cout << c << endl;
}
