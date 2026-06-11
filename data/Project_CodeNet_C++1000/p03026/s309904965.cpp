#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;

int main() {
  int N; cin >> N;
  Graph G(N);
  rep(i,N-1) {
    int a,b; cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> c(N);
  rep(i,N) cin >> c[i];

  vector<int> d(N);
  vector<pair <int, int>> num(N);

  rep(i,N) num[i] = make_pair(G[i].size(),i);

  sort(num.begin(),num.end());
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());

  queue<int> que;
  que.push(num[N-1].second);
  d[num[N-1].second] = c[0];
  int j = 1;
  int M = 0;
  while(!que.empty()) {
    int v = que.front();
    que.pop();
    rep(i,G[v].size()) {
      if (d[G[v][i]] != 0) continue;
      d[G[v][i]] = c[j];
      j++;
      que.push(G[v][i]);
      M += min(d[v],d[G[v][i]]);
    }
  }

  cout << M << endl;
  rep(i,N) cout << d[i] << " ";
  cout << endl;
  }