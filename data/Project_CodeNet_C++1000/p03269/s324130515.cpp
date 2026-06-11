#include <bits/stdc++.h>
using namespace std;
#define popCnt(x) (__builtin_popcountll(x))
typedef long long Long;
typedef unsigned long long ULong;

int l;
int n = 20;
int cnt_nodes = 0;

struct Edge {
  int from, to, w;
  Edge(int from, int to, int l) :
    from(from), to(to), w(l) {
  }
};

vector<Edge> edges;

void addEdge(int u, int v, int w) {
  edges.emplace_back(u, v, w);
}

int getNewNode() {
  return ++cnt_nodes;
}

int get(int l) {
  if (l == 1) {
    cnt_nodes = 1;
    return 1;
  }
  int prev_tail = get(l / 2);
  int curr_tail = getNewNode();
  addEdge(prev_tail, curr_tail, 0);
  addEdge(prev_tail, curr_tail, l / 2);

  if (l & 1) {
    addEdge(1, curr_tail, l - 1);
  }
  return curr_tail;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifdef Local
  freopen("test.in", "r", stdin);
#else
#define endl '\n'
#endif

  cin >> l;

  cout << get(l) << " ";

  cout << edges.size() << endl;
  for (auto& edge : edges) {
    cout << edge.from << " " << edge.to << " " << edge.w << endl;
  }

}
