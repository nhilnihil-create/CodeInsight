#include <iostream>
#include <iomanip>
#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <bitset>
#include <set>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);i++)
#define all(i,n) (i),(i+n)

int dx4[4]={1,0,-1,0};
int dy4[4]={0,-1,0,1};
int dx8[8]={1,0,-1,1,-1,1,0,-1};
int dy8[8]={1,1,1,0,0,-1,-1,-1};
int dx9[9]={0,1,0,-1,1,-1,1,0,-1};
int dy9[9]={0,1,1,1,0,0,-1,-1,-1};

typedef pair<int, int> P;
typedef pair<string, int> SP;
typedef long long ll;
typedef pair<ll, ll> PLL;

const int INF = 1e9;
const ll LLINF = 1e18;
const int MAX_V = 1e6+1;
const ll mod = 1000000007;
// << fixed << setprecision
// --------------------------------------
int n;
vector<P> g[100005];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  REP(i, n - 1) {
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    g[u].push_back(P(v, w));
    g[v].push_back(P(u, w));
  }

  vector<int> ans(n);
  ans[0] = 0;

  queue<tuple<int, int, int>> que;
  que.push({0, -1, 0});

  while(!que.empty()) {
    int now, from, color;
    tie(now, from, color) = que.front(); que.pop();
    for(P u : g[now]) {
      if(u.first == from) continue;
      int n_color = (color + u.second) % 2;
      ans[u.first] = n_color;
      que.push({u.first, now, n_color});
    }
  }

  REP(i, n) cout << ans[i] << endl;
}
