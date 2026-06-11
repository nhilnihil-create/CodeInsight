#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(101);
  int b, c;
  for (cin >> b; cin >> c;) if (a.at(c)++) b--;
  cout << b;
}