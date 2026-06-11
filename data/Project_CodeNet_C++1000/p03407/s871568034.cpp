#include <iostream>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B, C; cin >> A >> B >> C;
  cout << (A + B >= C ? "Yes" : "No") << "\n";
}