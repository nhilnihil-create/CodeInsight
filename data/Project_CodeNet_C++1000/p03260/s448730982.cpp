#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == 2 || b == 2) cout << "No\n";
  else cout << "Yes\n";
  return 0;
}