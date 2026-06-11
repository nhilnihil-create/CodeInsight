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
  ll a, b, c;
  cin >> a >> b >> c;
  c = min(c, a + b + 1);
  cout << b + c << endl;
  return 0;
}
