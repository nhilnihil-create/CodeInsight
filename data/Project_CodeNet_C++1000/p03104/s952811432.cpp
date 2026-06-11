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
  LL A, B; cin >> A >> B;
  LL A0 = A - (A % 4);
  LL B0 = B - (B % 4);

  LL SA = 0, SB = 0;
  for (LL i = A0; i < A; ++i) SA ^= i;
  for (LL i = B0; i <= B; ++i) SB ^= i;
  LL S = SB ^ SA;
  cout << S << endl;
}
