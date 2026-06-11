#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  string s; cin >> s;
  int r = 0, b = 0;
  for (char &c: s) {
    if (c == 'R') r++;
    else b++;
  }
  cout << (r > b ? "Yes" : "No") << endl;
}