#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int xdif = x1 - x2, ydif = y1 - y2;
  cout << x2 + ydif << " " << y2 - xdif << " " << x1 + ydif << " " << y1 - xdif<<endl;
}