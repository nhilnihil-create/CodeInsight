#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> P(M), Y(M);
  vector<pair<ll, ll>> PY(M);
  for (int i = 0; i < M; i++) {
    cin >> P[i] >> Y[i];
    PY[i] = {P[i], Y[i]};
  }
  sort(PY.begin(), PY.end());
  vector<map<ll, ll>> m(100005);
  int p_prev = -1, p, y = 1;
  int cnt = 1;
  for (auto py : PY) {
    p = py.first;
    if (p != p_prev) {
      p_prev = p;
      cnt = 1;
    }
    y = py.second;
    m[p][y] = cnt;
    cnt++;
  }
  for (int i = 0; i < M; i++) {
    printf("%06d%06d\n", P[i], m[P[i]][Y[i]]);
  }
  return 0;
}