#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N, M;
int X[101010], Y[101010], Z[101010];
vector<int> Graph[101010];
bool visited[101010];

void dfs(int cur) {
  visited[cur] = true;
  for (auto nv : Graph[cur]) {
    if (!visited[nv]) {
      dfs(nv);
    }
  }
}

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    int x, y, z;
    cin >> x >> y >> z;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
  }

  int ans = 0;
  repe(i, 1, N) {
    if (!visited[i]) {
      ++ans;
      dfs(i);
    }
  }
  cout << ans;
}
