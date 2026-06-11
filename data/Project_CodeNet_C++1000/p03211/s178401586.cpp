#include <bits/stdc++.h>
using namespace std;

int main(void) {
  string s; cin >> s;
  int n = s.length();
  
  int t, m = 1000;
  for (int i=0; i<(n-2); i++) {
    t = stoi(s.substr(i, 3));
    if (abs(753 - t) < m) m = abs(753 - t);
  }
  cout << m << endl;
  return 0;
}