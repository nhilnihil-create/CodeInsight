#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  
  int c = (a + b)/2*2;
  int d = (a + b) - c;
  
  cout << (a + b )/2 + d << endl;
}