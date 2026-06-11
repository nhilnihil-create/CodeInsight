#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  vector<int> D(3);
  
  D.at(0) = abs(A - B);
  D.at(1) = abs(B - C);
  D.at(2) = abs(C - A);
  sort(D.begin(), D.end());
  
  cout << D.at(0) + D.at(1) << endl;
}