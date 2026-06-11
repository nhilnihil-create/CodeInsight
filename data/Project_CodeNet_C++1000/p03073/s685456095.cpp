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
  int cnt1 = 0, cnt2 = 0;
  int d1 = 0, d2 = 1;
  for (int i = 0; i < S.size(); ++i) {
    int v = S[i] - '0';
    if (d1 != v) ++cnt1;
    if (d2 != v) ++cnt2;
    swap(d1, d2);
  }
  cout << min(cnt1, cnt2) << endl;
}
