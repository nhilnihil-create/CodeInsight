#include <cmath>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <iomanip>
#define mod(x) ((x % MOD) + MOD) % MOD
#define int long long int
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rrep(i, a, n) for(int i = n-1; i >= a; --i)

using namespace std;

typedef pair<int,int> P;

const int INF = 1e18;
const int MOD = 1e9+7;

template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " ";
  }
  return s;
}

struct edge {
  int to, cost;
  bool used;
};

void fill_potential(vector<int>& V, vector< vector<edge> >& G, int i, int x)
{
  if (V[i] != INF) {
    return;
  }

  V[i] = x;

  rep(j, 0, G[i].size()) {
    edge e = G[i][j];
    fill_potential(V, G, e.to, x + e.cost);
  }
}

bool dfs(vector<int>& V, vector< vector<edge> >& G, int i) {
  rep(j, 0, G[i].size()) {
    edge e = G[i][j];
    if (e.used) {
      continue;
    }
    e.used = true;
    if (V[i] + e.cost != V[e.to]) {
      return false;
    }
  }
  return true;
}



signed main()
{
  int N, M;
  cin >> N >> M;
  vector< vector<edge> > G(N, vector<edge>());
  int l, r, d;
  rep(i, 0, M) {
    cin >> l >> r >> d;
    l--; r--;
    G[l].push_back(edge{ r, -d, false });
    G[r].push_back(edge{ l,  d, false });
  }

  vector<int> V(N, INF);
  rep(i, 0, N) {
    fill_potential(V, G, i, 0);
  }
  rep(i, 0, N) {
    if (!dfs(V, G, i)) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
