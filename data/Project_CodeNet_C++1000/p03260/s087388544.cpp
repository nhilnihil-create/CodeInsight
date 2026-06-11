#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  bool ok = true;
  if (a % 2 == 0 || b % 2 == 0) ok = false;
  cout << (ok ? "Yes" : "No") << endl;
}