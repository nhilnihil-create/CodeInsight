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
  LL N, K; cin >> N >> K;
  if (K == 0) {
    cout << N * N << endl;
    return 0;
  }
  LL cnt = 0;
  for (int b = K + 1; b <= N; ++b) {
    LL x = N / b;
    LL r = N % b;
    cnt += x * (b - K) + max(0LL, r - K + 1);
  }
  cout << cnt << endl;
}
