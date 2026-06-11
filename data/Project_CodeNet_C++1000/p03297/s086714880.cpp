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

ll GCD(ll a, ll b) {
  if (a == 0) return b;
  return GCD(b % a, a);
}

int main()
{
  int tn;
  cin >> tn;
  for (int test = 0; test < tn; ++test) {
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (D < B || A - B < 0) {
      cout << "No\n";
    } else if (C >= B) {
      cout << "Yes\n";
    } else {
      A %= B;
      ll g = GCD(B, D);
      ll k = (B - A) / g;
      if ((B - A) % g == 0) k--;
      if (A + k * g > C) {
        cout << "No\n";
      } else {
        cout << "Yes\n";
      }
    }
  }
  return 0;
}
