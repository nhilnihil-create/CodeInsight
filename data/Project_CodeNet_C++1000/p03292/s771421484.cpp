#include <bits/stdc++.h>
using namespace std;

int main() {
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  bool a = A1 <= A2;
  bool b = A1 <= A3;
  bool c = A2 <= A3;
  bool d = A2 <= A1;
  bool e = A3 <= A1;
  bool f = A3 <= A2;
  
  if (a && c) {
    cout << (A3-A2)+(A2-A1) << endl;
  }
  else if (b && f) {
    cout << (A2-A3)+(A3-A1) << endl;
  }
  else if (d && b) {
    cout << (A3-A1)+(A1-A2) << endl;
  }
  else if (c && e) {
    cout << (A1-A3)+(A3-A2) << endl;
  }
  else if (e && a) {
    cout << (A2-A1)+(A1-A3) << endl;
  }
  else if (f && d) {
    cout << (A1-A2)+(A2-A3) << endl;
  }
}