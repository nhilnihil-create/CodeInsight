#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,x,countera,counterb;
  countera = 0;
  counterb = 0;
  cin >> n;
  vector<int> vecx(0);
  for (int j = 0; j < n; j++) {
    cin >> x;
    vecx.push_back(x);
  }
  sort(vecx.begin(), vecx.end());
  reverse(vecx.begin(), vecx.end());
  for (int j = 0; j < n; j++) {
    if (j % 2 == 0) {
      countera = countera + vecx.at(j);
    } else {
      counterb = counterb + vecx.at(j);
    }
  }
  cout << countera - counterb << endl;
}
