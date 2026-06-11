#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using P = pair<int, int>;
const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin >> k;
  vector<vector<int>> to(k), co(k);
  rep(i, k) {
    to[i].push_back((i+1)%k);
    co[i].push_back(1);
    to[i].push_back(i*10%k);
    co[i].push_back(0);
  }
  priority_queue<P, vector<P>, greater<P>> que;
  vector<int> node(k, INF);
  node[1] = 1;
  que.push({1, 1});
  while (!que.empty()) {
    int cost, now;
    tie(cost, now) = que.top();
    que.pop();
    if (cost > node[now])
      continue;
    rep(i, to[now].size()) {
      int next = to[now][i];
      int dist = co[now][i]+cost;
      if (chmin(node[next], dist))
        que.push({dist, next});
    }
  }
  cout << node[0] << endl;
  return 0;
}