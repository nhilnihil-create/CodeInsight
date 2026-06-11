#include <bits/stdc++.h>
using namespace std;

int main() {
  int t , a , b;
  cin >> t >> a >> b;
  
  if( (t * a) <= b ){
    cout << t * a << endl;
  }
  else{
    cout << b << endl;
  }
}