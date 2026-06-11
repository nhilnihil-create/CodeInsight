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
  string S; cin >> S;
  int c0 = 0, c1 = 0;
  for (int i = 0; i < S.size(); ++i) {
    if (S[i] == '0') ++c0;
    else             ++c1;
  }
  cout << min(c0, c1) * 2 << endl;
}
