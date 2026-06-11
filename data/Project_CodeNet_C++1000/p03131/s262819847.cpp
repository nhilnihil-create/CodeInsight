#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  ll k, a, b;
  cin >> k >> a >> b;
  ll result = k + 1;

  if (k + 1 >= a) {
    ll cur = 1;
    k -= a - 1;
    cur += a - 1;
    if (k % 2) {
      k--;
      cur++;
    }
    cur += k / 2 * (b - a);
    result = max(result, cur);
  }

  cout << result << endl;

  return 0;
}
