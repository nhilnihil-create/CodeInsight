#include <iostream>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int m[10] = {};
  m[a] += 1;
  m[b] += 1;
  m[c] += 1;
  m[d] += 1;
  if (m[1] == 1 && m[9] == 1 && m[7] == 1 && m[4] == 1) cout << "YES\n";
  else cout << "NO\n";
  return 0;
}