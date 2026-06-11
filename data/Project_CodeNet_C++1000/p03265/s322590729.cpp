#include<bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
  cout << x2 - (y2 - y1) << ' ';
  cout << y2 - (x1 - x2) << ' ';
  cout << x1 - (y2 - y1) << ' ';
  cout << y1 - (x1 - x2) << endl;
}