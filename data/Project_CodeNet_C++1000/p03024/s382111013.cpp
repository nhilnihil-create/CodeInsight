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
  std::string S; cin >> S;
  int cnt = 0;
  for (char x : S) if (x == 'o') ++cnt;

  cnt += 15 - S.size();
  if (cnt >= 8) cout << "YES" << endl;
  else          cout << "NO" << endl;
}
