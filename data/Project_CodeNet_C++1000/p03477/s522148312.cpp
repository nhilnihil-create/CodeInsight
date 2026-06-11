#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  string res;
  if(A + B > C + D)
    res = "Left";
  else if(A + B < C + D)
    res = "Right";
  else {
    res = "Balanced";
  }
  cout << res << endl;
}