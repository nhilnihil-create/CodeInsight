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
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n-1) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }
  priority_queue<int> pque;
  rep(i, n) {
    int c;
    cin >> c;
    pque.push(c);
  }
  vector<vector<int>> to(n);
  rep(i, n) {
    to[a[i]].push_back(b[i]);
    to[b[i]].push_back(a[i]);
  }
  vector<int> node(n);
  node[0] = pque.top();
  pque.pop();
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    for (auto next : to[now]) {
      if (!node[next]) {
        node[next] = pque.top();
        pque.pop();
        que.push(next);
      }
    }
  }
  int ans = 0;
  rep(i, n-1)
    ans += min(node[a[i]], node[b[i]]);
  cout << ans << endl;
  rep(i, n)
    printf("%d%c", node[i], i==n-1?'\n':' ');
  return 0;
}