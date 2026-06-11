#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b, c; cin >> a >> b >> c;
  cout << ((a != b && b != c && c != a) ? "Yes" : "No") << endl;
}