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
  vector<int> a(4);
  for (int i = 0; i < 4; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  cout << (a == vector<int>({1, 4, 7, 9}) ? "YES" : "NO") << endl;
  return 0;
}
