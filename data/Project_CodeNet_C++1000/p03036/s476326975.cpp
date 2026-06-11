#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int r, D;
  vector<int> x(2011);
  cin >> r >> D >> x.at(2000);
  for (int i=2000; i<2010; i++) {
    x.at(i+1)=r*x.at(i)-D;
  }
  for (int j=2001; j<2011; j++) {
    cout << x.at(j) << endl;
  }
}
