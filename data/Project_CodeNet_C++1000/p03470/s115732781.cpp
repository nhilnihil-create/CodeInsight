#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(101);
  int b = 0, c;
  for (cin >> c; cin >> c; a.at(c)++);
  for (c = 101; c--;) if (a.at(c)) b++;
  cout << b;
}