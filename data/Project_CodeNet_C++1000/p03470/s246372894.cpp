#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,a,b,numberconter,lapcounter,counter;
  counter = 0;
  cin >> n;
  vector<int> vecx(0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    vecx.push_back(x);
  }
  for (int i = 0; i < n; i++) { 
    lapcounter = 0;
    a = vecx.at(i);
    for (int j = 0; j < n; j++) {
      b = vecx.at(j);
      if (a == b) {
        lapcounter++;
        if (lapcounter != 1) {
          vecx.at(j) = 0;
        }
      }
    }
  }
  
  for (int j = 0; j < n; j++) {
    if (vecx.at(j) == 0) {
      counter++;
    }
  }
  cout << vecx.size() - counter ; 
    
}
          