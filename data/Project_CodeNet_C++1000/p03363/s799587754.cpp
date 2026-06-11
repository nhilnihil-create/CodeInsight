#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  map<ll, ll> m;
  m[0] = 1;
  ll sum = 0;
  ll result = 0;
  for (int i = 0; i < n; ++i) {
    ll x;
    cin >> x;
    sum += x;
    if (m.count(sum)) {
      result += m[sum];
    }
    m[sum]++;
  }
  cout << result << endl;
  return 0;
}
