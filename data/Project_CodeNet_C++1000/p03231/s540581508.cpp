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
typedef vector<int> vi;
typedef vector<ll> vll;

ll GCD(ll a, ll b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}

int main()
{
  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  int g = GCD(n, m);
  int i = 0;
  int j = 0;
  while (i < n) {
    if (s[i] != t[j]) {
      cout << -1 << endl;
      return 0;
    }
    i += n / g;
    j += m / g;
  }
  cout << n * m / g << endl;
  return 0;
}
