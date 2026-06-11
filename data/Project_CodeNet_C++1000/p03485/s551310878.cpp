#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b;
  cin >> a >> b;
  
  int ave;
  ave = (a + b) / 2;
  
  int even;
  even = (a + b) % 2;
  
  if (even != 0){
    
    ave = ave + 1;
    
  }
  
  cout << ave << endl;
  
 }