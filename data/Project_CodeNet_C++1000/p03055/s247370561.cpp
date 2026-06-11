#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <numeric>
#include <iomanip>

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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

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
struct INIT { INIT(){
  cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
}}INIT;

vector<int> bfs(int s, int N, vector<vector<int>> &graph){
  vector<int> dist(N, INF);
  dist[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int p = q.front(); q.pop();
    for(auto v : graph[p]){
      if(dist[v] != INF) continue;
      dist[v] = dist[p]+1;
      q.push(v);
    }
  }
  return dist;
}

int diameter(int N, vector<vector<int>> &graph){
  auto dist = bfs(0, N, graph);
  int root, ret = 0;
  REP(i, N){
    if(chmax(ret, dist[i])) root = i;
  }
  dist = bfs(root, N, graph);
  REP(i, N) chmax(ret, dist[i]);
  return ret;
}

signed main() {
  int N;
  cin >> N;

  if(N == 1){
    cout << "First" << "\n";
    return 0;
  }

  vector<vector<int>> graph(N);
  REP(i, N-1){
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  if(diameter(N, graph)%3 == 1) cout << "Second" << "\n";
  else cout << "First" << "\n";

  return 0;
}