#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int r;
  int g;
  cin >> r;
  cin >> g;
  
  if(r > 4500 || g > 4500){
 // invalid rating
  }
  
  cout << 2 * g - r << endl; 
}