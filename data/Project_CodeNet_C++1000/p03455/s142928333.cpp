#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  int p,m;
  cin >> a >> b;
  p = a * b;
  m = p % 2;
  if ( m == 1 ) {
    cout << "Odd" << endl;
  }
  else {
    cout << "Even" << endl;
  }
}