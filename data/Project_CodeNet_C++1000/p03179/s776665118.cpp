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

template<typename T>
auto makeNdVector(int n) {
  return vector<T>(n);
}

template<typename T, typename N, typename... Tail>
auto makeNdVector(const N& n, const Tail&... tail) {
  auto vec = makeNdVector<T>(tail...);
  vector<decltype(vec)> vecs(n, vec);
  return vecs;
}

void add(LL& a, LL b) { a = (a + b) % kMod; }

int main() {
  int N; cin >> N;
  string S; cin >> S;
  auto dp = makeNdVector<LL>(N + 1, N + 1);

  for (int j = 0; j < N; ++j) dp[0][j] = 1;

  for (int i = 0; i < N; ++i) {
    if (S[i] == '<') {
      dp[i + 1][0] = dp[i][0];
      for (int j = 0; j + 1 < N - i - 1; ++j) {
        add(dp[i + 1][j + 1], dp[i + 1][j] + dp[i][j + 1]);
      }
    } else {  // '>'
      for (int j = N - i - 1; j >= 0; --j) {
        add(dp[i + 1][j], dp[i + 1][j + 1] + dp[i][j + 1]);
      }
    }
  }
  cout << dp[N-1][0] << endl;
}
