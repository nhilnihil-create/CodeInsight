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
auto makeNdVector(int n, const T& v) {
  return vector<T>(n, v);
}

template<typename T, typename N, typename... Tail>
auto makeNdVector(const N& n, const Tail&... tail) {
  auto vec = makeNdVector<T>(tail...);
  vector<decltype(vec)> vecs(n, vec);
  return vecs;
}

int main() {
  LL N, M; cin >> N >> M;
  if (N == 1 && M == 1) {
    cout << 1 << endl;
  } else if (N == 1 || M == 1) {
    LL v = max(N, M);
    cout << v - 2 << endl;
  } else {
    cout << (N-2LL)*(M-2LL) << endl;
  }
}
