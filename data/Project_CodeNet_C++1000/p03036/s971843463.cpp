#include <bits/stdc++.h>
using namespace std;

int main() {
  int r, D, xs;
  vector<int> x(10);
  cin >> r >> D >> xs;
  
  x.at(0) = r*xs - D;
  cout << x.at(0) << endl;
  
  for (int i=0; i<9; i++) {
    x.at(i+1) = r*x.at(i) - D;
    cout << x.at(i+1) << endl;
  }
}

