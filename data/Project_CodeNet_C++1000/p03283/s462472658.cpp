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
  int N, M, Q; cin >> N >> M >> Q;
  vector<vector<LL>> p(N + 1, vector<LL>(N + 1, 0));
  for (int i = 0; i < M; ++i) {
    int L, R; cin >> L >> R;
    ++p[L][R];
  }

  vector<vector<LL>> S(N + 1, vector<LL>(N + 1, 0));
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= N; ++j) {
      S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + p[i][j];
    }
  }

  for (int i = 0; i < Q; ++i) {
    int L, R; cin >> L >> R;
    cout << S[R][R] - S[R][L-1] - S[L-1][R] + S[L-1][L-1] << endl;
  }
}
