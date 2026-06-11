#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  if (n / 2 * 2 == n)
    cout << n << endl;
  else
    cout << 2 * n << endl;
}
