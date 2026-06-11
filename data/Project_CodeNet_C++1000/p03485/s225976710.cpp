#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  double c;
  cin >> a >> b;
  
  c = (a + b) / 2.0;
  
  if((a + b) % 2 == 1){
    c = c + 0.5;
  } 
  
  cout << c << endl;
}
