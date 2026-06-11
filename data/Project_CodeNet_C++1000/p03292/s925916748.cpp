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
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> X(3);
  X[0] = abs(A - B);
  X[1] = abs(A - C);
  X[2] = abs(B - C);
  sort(X.begin(), X.end());
  cout << X[0] + X[1] <<endl;
}