#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
vector<int> parent;
vector<int> nodes;

int getParent(int x) {
  int y = x;
  while (y != parent[y]) y = parent[y];
  parent[x] = y;
  return y;
}

void unite(int x, int y) {
  x = getParent(x);
  y = getParent(y);
  if (x == y) return;
  if (nodes[x] < nodes[y]) swap(x, y);
  parent[y] = x;
  nodes[x] += nodes[y];
}

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  parent.resize(N);
  nodes.resize(N);
  rep(i, N) {
    parent[i] = i;
    nodes[i] = 1;
  }
  rep(i, M) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    unite(x, y);
  }

  int answer = 0;
  rep(i, N) {
    if (i == getParent(i)) ++answer;
  }
  cout << answer << endl;
  return 0;
}