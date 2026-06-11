#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#define Rep(i, n) for(int i=0;i<n;++i)
#define rep(i, n) for(int i=1;i<=n;++i)
#define ll long long int
#define INF 100000000
#define INFLL 100000000000
#define MOD 1000000007
#define PI 3.14159265359
#define All(a) (a).begin(), (a).end()

using namespace std;
using P = pair<ll, ll>;
 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Edge {
  int to;     
  ll weight; 
  Edge(int t, ll w) : to(t), weight(w) { }
};



int N;
int d[110000];
using Graph = vector<vector<int>>;

int main () {
  cin >> N;
  Graph G(N+1);

  Rep(i, N-1) {
    int a, b;
    cin >> a >> b;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  priority_queue<int> pq;

  Rep(i, N) {
    int c;
    cin >> c;
    pq.push(c);
  }

  queue<int> que;
  que.push(1);
  vector<bool> seen(N+1);
  seen.assign(N+1, false);


  while (!que.empty()) {
    int v = que.front();
    que.pop();
    seen[v] = true;
    int s = pq.top(); pq.pop();
    d[v] = s;

    for (int nv: G[v]) {
      if (seen[nv]) continue;

      que.push(nv);
    }
  }

  que.push(1);
  seen.assign(N+1, false);
  ll ans = 0;

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    seen[v] = true;

    for (int nv: G[v]) {
      if (seen[nv]) continue;

      ans += d[nv];
      que.push(nv);
    }
  }

  cout << ans << "\n";

  rep(i, N-1) {
    cout << d[i] << " ";
  }
  cout << d[N] << "\n";

}