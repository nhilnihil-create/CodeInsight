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
  int n, k;
  cin >> n >> k;
  cout << (n >= 2 * k - 1 ? "YES" : "NO") << endl;
  return 0;
}
