#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int R; cin >> R;
  if (R < 1200) cout << "ABC\n";
  else if (R < 2800) cout << "ARC\n";
  else cout << "AGC\n";
}