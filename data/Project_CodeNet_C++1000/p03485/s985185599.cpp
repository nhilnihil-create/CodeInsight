#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  double x;
  
  cin >> a >> b;
  x = (a+b)*0.5;
  c = (a+b)/2 + ((a+b)/2 - x !=0);
  
  cout << c << endl;
  
  
}