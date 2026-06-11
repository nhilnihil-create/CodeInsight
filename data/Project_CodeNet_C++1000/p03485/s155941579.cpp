#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  double x;
  
  cin >> a;
  cin >> b;
  x = (a+b) / 2;
  
  if( (a+b) % 2 == 1){
    x = x+1;
  }
  
  cout << x << endl;
}
