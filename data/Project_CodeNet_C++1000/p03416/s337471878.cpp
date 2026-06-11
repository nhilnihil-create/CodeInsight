#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string n;
  cin >> a >> b;
  
  int cnt = 0;
  for (int i = a; i <= b; ++i) {
    n = to_string(i);
    if (n.at(0) == n.at(4) && n.at(1) == n.at(3)) { ++cnt; }
  }
  cout << cnt << endl;
}
