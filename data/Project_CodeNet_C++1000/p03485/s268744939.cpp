#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int a,b;
  cin >> a >> b;
  double x = (a + b) / 2.0;
  int y = (a + b) / 2.0;
  double z = x - y;
  if(z < 0.5){
      cout << y << endl;
  }
  else {
      y++;
      cout << y << endl;
  }
  
  
}