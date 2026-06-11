#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;


struct UnionFindTree {
  std::vector<int> data;

  UnionFindTree(int size) : data(size, -1) { }
  bool Unite(int x, int y) {
    x = Root(x); y = Root(y);
    if (x != y) {
      if (data[y] < data[x]) std::swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
    return x != y;
  }
  bool IsSameRoot(int x, int y) {
    return Root(x) == Root(y);
  }
  int Root(int x) {
    return data[x] < 0 ? x : data[x] = Root(data[x]);
  }
  int Size(int x) { return -data[Root(x)]; }
};

int main() {
  int N, M; cin >> N >> M;
  UnionFindTree tree(N + 1);
  for (int i = 0; i < M; ++i) {
    int X, Y, Z; cin >> X >> Y >> Z;
    tree.Unite(X, Y);
  }

  set<int> s;
  for (int i = 1; i <= N; ++i) {
    s.insert(tree.Root(i));
  }
  cout << s.size() << endl;
}
