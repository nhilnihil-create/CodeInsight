#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

constexpr int DEBUG = 1;

struct Edge {
  int from, to, w;
};

int fls(int x) {
  int count = 0;
  while (x > 0) {
    x /= 2;
    count++;
  }
  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int l;
  cin >> l;
  int n = fls(l);

  vector<Edge> edges;
  for (int i = 0; i < n - 1; i++) {
    edges.push_back(Edge({i + 1, i, 0}));
    edges.push_back(Edge({i + 1, i, 1 << i}));
  }


  int current = 1 << (n - 1);
  int r = l - (1 << (n - 1));
  while (r > 0) {
    int v = fls(r) - 1;
    edges.push_back(Edge({n - 1, v, current}));
    current += 1 << v;
    r -= 1 << v;
  }

  cout << n << " " << edges.size() << endl;
  for (const auto& edge : edges) {
    int output_from = n - edge.from;
    int output_to = n - edge.to;
    cout << output_from << " " << output_to << " " << edge.w << endl;
  }
}