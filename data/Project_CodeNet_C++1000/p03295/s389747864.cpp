#include <math.h>

#include <algorithm>
#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
using ll = long long;
const int INF = 1e8;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> ab(M, vector<ll>(2));
  for (int i = 0; i < M; i++) {
    cin >> ab[i][0] >> ab[i][1];
  }
  sort(ab.begin(), ab.end(),
       [](const vector<ll> &alpha, const vector<ll> &beta) {
         return alpha[1] < beta[1];
       });

  int ans = 1;
  ll x_last = ab[0][1];
  for (int i = 1; i < M; i++) {
    if (ab[i][0] < x_last) {
      continue;
    }
    x_last = ab[i][1];
    ans++;
  }

  cout << ans << endl;

  return 0;
}
