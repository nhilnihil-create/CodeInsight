#include <bits/stdc++.h>
using namespace std;


int main() {
 int a;
 int b;
 cin >> a >> b;
  int x;
  x = (a + b) / 2 ;
  if (2*x < a + b){
    x = x + 1;
  }
  cout << x << endl;
}
