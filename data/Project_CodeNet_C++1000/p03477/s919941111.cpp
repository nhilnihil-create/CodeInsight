#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a + b > c + d) cout << "Left\n";
  else if (a + b < c + d) cout << "Right\n";
  else cout << "Balanced\n";
  return 0;
}
