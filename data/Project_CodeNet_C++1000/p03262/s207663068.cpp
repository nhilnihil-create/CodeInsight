#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  ll n, x;
  cin >> n >> x;
  ll v;
  cin >> v;
  ll d = abs(v - x);
  while (cin >> v)
    d = __gcd(d, abs(v - x));
  cout << d << endl;
}
