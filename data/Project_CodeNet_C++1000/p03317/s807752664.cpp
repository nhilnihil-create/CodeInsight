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
  int index = -1;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    cin >> A[i];
  }

  int i = K, cnt = 1;
  while (i < N) {
    ++cnt; i += K - 1;
  }
  cout << cnt << endl;
}
