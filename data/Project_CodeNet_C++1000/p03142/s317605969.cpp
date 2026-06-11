#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

vector<vector<int> > G;
vector<int> d;

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> in(n,0), A(n+m-1), B(n+m-1);
  G.resize(n);
  d.resize(n,0);
  rep(i,n+m-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    A[i] = a;
    B[i] = b;
    in[b]++;
    G[a].push_back(b);
  }
  int s = 0;
  rep(i,n) {
    if (in[i] == 0) {
      s = i;
      break;
    }
  }

  queue<int> que;
  que.push(s);

  while (!que.empty()) {
    int p = que.front(); que.pop();
    for (auto v : G[p]) {
      in[v]--;
      d[v] = max(d[v], d[p] + 1);
      if (in[v] == 0) que.push(v);
    } 
  }

  vector<int> res(n,-1);
  rep(i,n+m-1) {
    int u = A[i];
    int v = B[i];
    if (d[v] - d[u] == 1) res[v] = u;
  }
  rep(i,n) cout << res[i] + 1 << endl;
  return 0;
} 