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
  long double N, K; cin >> N >> K;
  long double p = 0;
  for (int i = 1; i <= N; ++i) {
    if (i >= K) {
      p += 1.0;
    } else {
      LL cnt = ceil(log2(K / i));
      p += 1.0 / (pow(2, cnt));
    }
  }
  double p2 = p / N;
  printf("%.12f\n", p2);
}
