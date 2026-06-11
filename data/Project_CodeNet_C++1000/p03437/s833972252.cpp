#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int X, Y;
  cin >> X >> Y;
  if (X % Y == 0) return cout << "-1" << "\n", 0;
  cout << X << "\n";
}