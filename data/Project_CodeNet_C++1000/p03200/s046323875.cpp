#include <iostream>

using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  ll b{}, ans{};
  for (char c: S) {
    if (c == 'B') ++b;
    else ans += b;
  }
  cout << ans << endl;
}
