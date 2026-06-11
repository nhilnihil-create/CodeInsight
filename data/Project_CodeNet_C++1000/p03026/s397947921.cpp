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


signed main() {
  int N;
  cin >> N;

  vector<vector<int>> graph(N);
  REP(i, N-1){
    int u, v;
    cin >> u >> v;
    u--; v--;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }

  vector<int> A(N);
  REP(i, N) cin >> A[i];
  sort(ALL(A), greater<>());

  queue<int> q;
  q.push(0);
  vector<int> ans(N);
  vector<bool> visited(N, false);
  int cnt = 0;
  while(!q.empty()){
    int p = q.front(); q.pop();
    visited[p] = true;
    ans[p] = A[cnt++];

    for(auto v : graph[p]){
      if(visited[v]) continue;
      q.push(v);
    }
  }

  int sum = 0;
  FOR(i, 1, N) sum += A[i];
  cout << sum << endl;
  REP(i, N){
    cout << ans[i]; SPBR(i, N);
  }

  return 0;
}