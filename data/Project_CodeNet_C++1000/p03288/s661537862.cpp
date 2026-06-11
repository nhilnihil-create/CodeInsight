#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a<1200) {
    cout << "ABC" << endl;
  }
  if (a>=1200 && a<2800) {
    cout << "ARC" << endl;
  }
  if (a > 2799) {
    cout << "AGC" << endl;
  }
}