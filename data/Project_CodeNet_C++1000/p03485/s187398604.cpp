#include <bits/stdc++.h>
using namespace std;

int a, b, x;

int main(){
  
  cin >> a >> b;
  x = (a + b)/2;
  if( ((a+b) % 2) == 1)
    x++;

  cout << x << endl;

  return 0;
}
