#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;
using ll = long long int;

int main() {
  ll N;
  cin >> N;

  ll prev_t = 0;
  ll prev_x = 0;
  ll prev_y = 0;
  bool ok = true;

  for (ll i = 0; i < N; i++)
  {
    ll ti, xi, yi;
    cin >> ti >> xi >> yi;

    ll walk = ti - prev_t;
    ll dist = abs(xi - prev_x) + abs(yi - prev_y);
    if (walk < dist) {
      ok = false;
    }
    if ((walk - dist) % 2 == 1) {
      ok = false;
    }

    prev_t = ti;
    prev_x = xi;
    prev_y = yi;
  }
  cout << (ok ? "Yes" : "No") << endl;
    
}