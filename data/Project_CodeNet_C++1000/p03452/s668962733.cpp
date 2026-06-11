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
  int to, diff;
};


bool dfs(vector<int>& x, vector< vector<edge> >& G, vector<bool>& used, int i) {
  stack<int> st;
  st.push(i);
  x[i] = 0;
  while (!st.empty()) {
    int i = st.top(); st.pop();
    rep(j, 0, G[i].size()) {
      edge e = G[i][j];
      if (used[e.to]) {
        if (x[i] + e.diff != x[e.to]) {
          return false;
        }
      } else {
        used[e.to] = true;
        x[e.to] = x[i] + e.diff;
        st.push(e.to);
      }
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
    G[l].push_back(edge{ r, -d });
    G[r].push_back(edge{ l,  d });
  }

  vector<int> x(N);
  vector<bool> used(N, false);
  rep(i, 0, N) {
    if (!used[i]) {
      x[i] = 0;
      used[i] = true;
      if (!dfs(x, G, used, i)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }

  cout << "Yes" << endl;
  return 0;
}
