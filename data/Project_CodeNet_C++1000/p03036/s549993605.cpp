#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x0, r, d;
  cin >> r >> d >> x0;
  vector<int> x(10);
  for(int i = 0; i < 10; i++){
    x.at(i) = r*x0 - d;
    x0 = x.at(i);
    cout << x.at(i) << endl;
  }
}