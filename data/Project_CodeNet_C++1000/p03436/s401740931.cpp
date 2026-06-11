#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

vector<pair<ll, ll>> directions = {
  {+0, +1},
  {+0, -1},
  {+1, +0},
  {-1, +0},
};
ll bfs(ll sy, ll sx, vector<vector<char>> &grid) {
  struct Value {
    ll y, x, cost;
  };

  queue<Value> que;
  que.push({sy, sx, 0});

  while (!que.empty()) {
    Value node = que.front();
    que.pop();

    // --- 終端 ---
    if (node.y == grid.size() - 1 && node.x == grid[0].size() - 1) {
      return node.cost + 1;
    }

    if (grid[node.y][node.x] != '.') continue;
    grid[node.y][node.x] = '@';

    for(auto d: directions) {
      ll ny = node.y + d.first, nx = node.x + d.second;
      if (0 <= ny && ny < grid.size() && 0 <= nx && nx < grid[ny].size() && grid[ny][nx] == '.') {
        que.push({ny, nx, node.cost + 1});
      }
    }
  }
  return 0;
}

int main() {
  ll input(h, w);
  vector<vector<char>> grid(h, vector<char>(w));
  ll white = 0;
  REP(i, h) REP(j, w) {
    cin >> grid[i][j];
    if (grid[i][j] == '.') white++;
  }

  ll cnt = bfs(0, 0, grid);
  if (cnt == 0) cout << -1 << endl;
  else cout << white - cnt << endl;
}
