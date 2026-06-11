#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> par;
vector<int> rankk;

void init(int n) {
  par.resize(n);
  rankk.resize(n);
  for (int i = 0; i < n; i++) {
    par[i] = i;
    rankk[i] = 0;
  }
}

int root(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = root(par[x]);
  }
}

bool same(int x, int y) { return root(x) == root(y); }

void unite(int x, int y) {
  x = root(x);
  y = root(y);
  if (x == y) return;

  par[x] = y;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  init(n);

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    unite(x, y);
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (same(i, p[i] - 1)) {
      count++;
    }
  }

  cout << count << endl;
}