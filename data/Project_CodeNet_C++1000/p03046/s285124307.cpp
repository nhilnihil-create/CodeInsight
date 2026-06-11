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
  int M, K; cin >> M >> K;
  int N = 1;
  for (int i = 0; i < M; ++i) N *= 2;
  if (K >= N) {
    cout << -1 << endl;
    return 0;
  }
  if (M == 1 && K == 1) {
    cout << -1 << endl;
    return 0;
  }

  if (K == 0) {
    for (int i = 0; i < N; ++i) {
      cout << i << " " << i << " ";
    }
    cout << endl;
    return 0;
  }

  for (int i = 0;  i < N; ++i) {
    if (i == K) continue;
    cout << i << " ";
  }
  cout << K << " ";
  for (int i = N - 1;  i >= 0; --i) {
    if (i == K) continue;
    cout << i << " ";
  }
  cout << K << " " << endl;;
}
