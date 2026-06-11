#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a * b - (a + b - 1);
  cout << ans << endl;
  return 0;
}
