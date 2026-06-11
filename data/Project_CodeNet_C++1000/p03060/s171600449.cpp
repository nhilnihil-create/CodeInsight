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
ll N;
vector<ll> V, C;

int dfs(int i, int value, int cost) {
  if (i == N) return value - cost;
  int cand1 = dfs(i + 1, value + V[i], cost + C[i]);
  int cand2 = dfs(i + 1, value, cost);
  return max(cand1, cand2);
}

int main() {
  cin >> N;
  V.resize(N), C.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> V[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> C[i];
  }
  int ans = dfs(0, 0, 0);
  cout << ans << endl;
  return 0;
}