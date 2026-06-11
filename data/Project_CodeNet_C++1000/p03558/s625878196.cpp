#define dbg(...) fprintf(stderr,__VA_ARGS__)
#define dpr(x) cerr<<#x<<": "<<x<<endl;
#define dprc(c) do{cerr<<#c<<":";for(auto&_i:(c)){cerr<<" "<<_i;}cerr<<endl;}while(0)
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int INF = 1e9+7;
#define all(c) (c).begin(), (c).end()
#define tr(i,c) for(auto i=(c).begin();i!=(c).end();i++)
#define rtr(i,c) for(auto i=(c).rbegin();i!=(c).rend();i++)
#define rep(i,b) for(auto i=0;i<(b);i++)
#define pb push_back
#define sz(c) int((c).size())

typedef struct {
  int from, to, cost;
} edge;

int main(int argc, char **argv)
{

  int k;

  cin >> k;

  vector<vector<edge>> g(k);

  for (int i = 0; i < k; i++) {
    g[i].pb(edge{i, (i+1)%k, 1});
    g[i].pb(edge{i, (i*10)%k, 0});
  }

  auto cmp = [](edge a, edge b) { return a.cost > b.cost; };
  priority_queue<edge, vector<edge>, decltype(cmp)> pq(cmp);

  vector<int> ans(k);
  for (int i = 0; i < k; i++) {
    ans[i] = INT_MAX;
  }

  ans[1] = 0;
  for (int i = 0; i < sz(g[1]); i++) {
    pq.push(g[1][i]);
  }

  while (!pq.empty()) {
    edge e = pq.top(); pq.pop();
    if (ans[e.to] <= ans[e.from]+e.cost) continue;
    ans[e.to] = ans[e.from]+e.cost;
    for (int i = 0; i < sz(g[e.to]); i++) {
      pq.push(g[e.to][i]);
    }
  }

  cout << ans[0] + 1 << endl;

  return 0;
}


