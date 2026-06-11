#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,countera,counterb,counter,subcounter,numbercounter,lapcounter;
  subcounter = 0;
  countera = 0;
  counterb = 0;
  lapcounter = 0;
  vector<int> vecx(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    vecx.push_back(x);
  }

  for (int j = 0; j < n; j++) {
    lapcounter++;
    subcounter = 0;
    for (int i = 0; i < n; i++) {
      counter = vecx.at(i);
      if (counter > subcounter) {
        numbercounter = i;
        subcounter = counter;
      }
    }
    if (lapcounter % 2 == 1) {
      countera = countera + subcounter;
    } else {
      counterb = counterb + subcounter;
    }
    vecx.at(numbercounter) = 0;
  }
  cout << countera-counterb;
    
    
    
}