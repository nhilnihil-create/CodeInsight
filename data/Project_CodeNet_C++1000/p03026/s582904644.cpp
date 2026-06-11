#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
#include<deque>
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  };
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(c.rbegin(), c.rend());
  vector<int> ans(n);
  int s = 0;
  queue<int> q;

  int cur = 0;
  auto push = [&](int v) {
    if(ans[v] > 0) return;
    ans[v] = c[cur];
    cur++;
    q.push(v);
  };
  push(0);

  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int u : graph[v]) {
      push(u);
    }
  }

  for(int i = 1; i < n; ++i) s += c[i];
  cout << s << endl;
  rep(i, n) {
    cout << ans[i] << endl;
  }

}
