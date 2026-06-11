#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int d;
  cin >> d;
  cout << "Christmas";
  for (int i = 0; i < 25 - d; ++i) cout << " Eve";
  cout << '\n';
  return 0;
}