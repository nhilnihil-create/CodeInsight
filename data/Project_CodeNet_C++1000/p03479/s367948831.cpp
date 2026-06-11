#include <iostream>

using namespace std;

int main() {
  long long X, Y, ans{};
  cin >> X >> Y;
  while (X <= Y) Y >>= 1, ++ans;
  cout << ans << endl;
}
