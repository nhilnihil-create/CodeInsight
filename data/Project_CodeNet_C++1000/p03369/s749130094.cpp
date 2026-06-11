#include <bits/stdc++.h>
using namespace std;

int main() {
  string t; cin >> t;
  int c=700;
  for (int i=0; i<3; i++) {
    if (t[i]=='o') c+=100;
  }
  cout << c << endl;
}