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
  int N, K; cin >> N >> K;
  LL x = N / K;
  if (K % 2 == 0) {
    LL y = N / (K / 2) - x;
    cout << x * x * x  + y * y * y << endl;
  } else {
    cout << x * x * x << endl;
  }
}
