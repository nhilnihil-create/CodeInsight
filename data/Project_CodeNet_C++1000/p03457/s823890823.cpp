#include <bits/stdc++.h>
using namespace std;

// これ以降の行は変更しなくてよい

int main() {
  int n;
  cin >> n;
  vector<int> t(n), x(n), y(n);
  for (int i = 0; i < n; i++) cin >> t[i] >> x[i] >> y[i];

  for (int i = 0; i < n; i++) {
    int ti, xi, yi;
    if (i == 0) {
      ti = t[i];
      xi = x[i];
      yi = y[i];
    }
    else{
      ti = t[i] - t[i-1];
      xi = x[i] - x[i-1];
      yi = y[i] - y[i-1];
    }

    // cout << ti << " " << xi << " "<< yi << " " << endl;

    if ((abs(xi+yi) <= ti) && (abs(xi+yi-ti)%2 == 0)) continue;
    else {cout << "No" << endl; return 0;}
  }
  cout << "Yes" << endl;
  return 0;
}
