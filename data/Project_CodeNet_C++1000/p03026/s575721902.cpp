#include <bits/stdc++.h>
using namespace std;
// using Graph = vector<vector<int>>;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  REP(i, N - 1) {
    int a, b;
    cin >> a >> b;
    G[a - 1].push_back(b - 1);
    G[b - 1].push_back(a - 1);
  }
  vector<int> c(N);
  REP(i, N) {
    cin >> c[i];
  }
  sort(c.begin(), c.end(),greater<int>());

  vector<int> seen(N, false);
  queue<int> todo;
  vector<int> ans(N);
  
  int cursol = 0;
  seen[0] = true;
  todo.push(0);
  while (!todo.empty()) {
    int here = todo.front();
    todo.pop();
    // cout << here << ' ' << c[cursol] << endl;
    ans[here] = c[cursol];
    cursol++;

    for (int node: G[here]) {
      if (seen[node] == false) {
        todo.push(node);
        seen[node] = true;
      }
    }
  }

  int sum = 0;
  for (int i = 1; i < N; i++) sum += c[i];
  cout << sum << endl;
  REP(i, N) {
    if (i != N - 1) cout << ans[i] << ' ';
    else cout << ans[i] << endl; 
  }
  return 0;
}