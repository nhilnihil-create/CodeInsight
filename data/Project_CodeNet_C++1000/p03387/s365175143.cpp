#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int main() {
  vector<int> v(3); cin >> v[0] >> v[1] >> v[2];
  sort(v.begin(), v.end());
  int cnt = 2 * v[2] - v[0] - v[1];
  if (cnt % 2 == 0) cout << cnt/2 << endl;
  else              cout << (cnt + 3)/2 << endl;
}
