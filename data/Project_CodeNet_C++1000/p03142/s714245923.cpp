#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>

// output
#define SPBR(w, n) std::cout<<(w + 1 == n ? '\n' : ' ');
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
// utility
#define ALL(i) (i).begin(), (i).end()
#define FOR(i, a, n) for(int i=(a);i<(n);++i)
#define RFOR(i, a, n) for(int i=(n)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=int(n)-1;i>=0;--i)
#define IN(a, x, b) (a<=x && x<b)
#define OUT(a, x, b) (x<a || b<=x)
template<class T> inline T chmax(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T chmin(T& a, const T b) { return a = (a > b) ? b : a; }

// type/const
#define int ll
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MOD = 1000000007;
/* const int MOD = 998244353; */
const int INF = 1e18;
const double PI = acos(-1);

using namespace std;

vector<int> tsort_Kahn(const vector<vector<int>>& g){
  const int V = g.size();
  vector<int> indeg(V, 0);
  stack<int> S;

  for(auto& u_out_edges : g){
    for(auto& v : u_out_edges){
      indeg[v]++;
    }
  }

  REP(i, V) if(indeg[i] == 0) S.push(i);

  vector<int> ans;
  while(S.size()){
    int u = S.top(); S.pop();
    ans.emplace_back(u);
    for(auto& v : g[u]){
      indeg[v]--;
      if(indeg[v] == 0) S.push(v);
    }
  }
  return ans;
}

signed main() {
  int N, M; 
  cin >> N >> M;

  vector<int> x(N+M-1), y(N+M-1);
  vector<vector<int>> graph(N);
  REP(i, N+M-1){
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
    graph[x[i]].emplace_back(y[i]);
  }

  vector<int> vec = tsort_Kahn(graph);

  vector<int> pos(N, 0);
  REP(i, N){
    pos[vec[i]] = i;
  }

  vector<int> parent(N, -1);
  REP(i, N+M-1){
    chmax(parent[pos[y[i]]], pos[x[i]]);
  }

  vector<int> ans(N);
  REP(i, N){
    if(parent[i] == -1) ans[vec[i]] = 0;
    else ans[vec[i]] = vec[parent[i]]+1;
  }

  REP(i, N){
    cout << ans[i] << endl;
  }

  return 0;
}