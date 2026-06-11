#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  
  int an = a * n;
  
  if (an < b) {cout << an << endl;}
  else {cout << b << endl;}
}