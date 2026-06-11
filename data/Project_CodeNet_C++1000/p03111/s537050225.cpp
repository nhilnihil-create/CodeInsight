#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int n, a, b, c;
int ans = 0;
vector<int> l;

// no...使用済みの本数,x...Aの長さ,...
int dfs(int no, int x, int y, int z) {
  if (no == n) {
    if (!x || !y || !z) return INF;
    return abs(a - x) + abs(b - y) + abs(c - z) -
           30;  // 30は1つもない状態から竹を追加するときにmergeのぶん足しているから
  }
  int x1 = dfs(no + 1, x, y, z);
  int x2 = dfs(no + 1, x + l[no], y, z) + 10;
  int x3 = dfs(no + 1, x, y + l[no], z) + 10;
  int x4 = dfs(no + 1, x, y, z + l[no]) + 10;
  return min({x1, x2, x3, x4});
  return ans;
}

int main() {
  cin >> n >> a >> b >> c;
  l.resize(n);
  rep(i, n) cin >> l[i];
  cout << dfs(0, 0, 0, 0) << endl;
  return 0;
}
