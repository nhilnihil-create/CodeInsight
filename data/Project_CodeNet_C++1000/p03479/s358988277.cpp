#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long int;

int main() {
  ll X, Y;
  cin >> X >> Y;

  ll ans = 0;
  while (X <= Y)
  {
    X *= 2;
    ans += 1;
  }
  cout << ans << endl;
}