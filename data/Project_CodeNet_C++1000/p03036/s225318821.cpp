#include <bits/stdc++.h>
using namespace std;

int main() {
  int r,d,x2000;
  cin >> r >> d >> x2000;
  
  vector<int> x(11);
  x.at(0) = x2000;
  
  for(int i = 1; i < 11; i++){
    x.at(i) = r*x.at(i-1)-d;
    cout << x.at(i) << endl;
  }
  
}