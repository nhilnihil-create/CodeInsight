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
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  vector<int> in(n);
  rep(i, n-1+m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    to[a].push_back(b);
    in[b]++;
  }
  queue<int> que;
  rep(i, n) {
    if (!in[i])
      que.push(i);
  }
  vector<int> tps;
  while (!que.empty()) {
    int a = que.front();
    que.pop();
    tps.push_back(a);
    for (auto e : to[a]) {
      in[e]--;
      if (!in[e])
        que.push(e);
    }
  }
  vector<int> ans(n);
  rep(i, n) {
    for (auto e : to[tps[i]])
      ans[e] = tps[i]+1;
  }
  rep(i, n)
    cout << ans[i] << endl;
  return 0;
}