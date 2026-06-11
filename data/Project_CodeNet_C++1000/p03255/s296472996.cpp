#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  ll n;
  cin >> n;
  ll X;
  cin >> X;
  vector<ll> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

//  X = 1e9;
//  n = 2e5;
//  x = vector<ll>(n, 1e9);

  reverse(x.begin(), x.end());
  vector<ll> s(2 * n + 1);
  for (int i = 0; i < n; ++i) s[i + 1] = s[i] + x[i];
  for (int i = n + 1; i < s.size(); ++i) s[i] = s[i - 1];



  ll result = ll(1e18);
  for (ll k = 1; k <= n; ++k) {
    ll curResult = (n + k) * X;
    double curResultDouble = (n + k) * X;
    ll mul = 3;
    for (int at = 0; at <= n; at += k) {
      curResult += (s[at + k] - s[at]) * (mul + (mul == 3) * 2);
      curResultDouble += (s[at + k] - s[at]) * (mul + (mul == 3) * 2);
      mul += 2;
    }
    if (curResultDouble > 1e18) continue;
    //cerr << k << " " << curResult << endl;
    result = min(result, curResult);
  }
  cout << result << endl;

  return 0;
}
