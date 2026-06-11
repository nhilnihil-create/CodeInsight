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
vector<int> cost;
vector<P> grid;
int h, w, d;
int dfs(int p) {
  if(cost[p] != INF) return cost[p];
  if(p + d > h * w) return cost[p] = 0;
  int x = grid[p].first, y = grid[p].second;
  int nextx = grid[p + d].first, nexty = grid[p + d].second;
  return cost[p] = abs(nextx - x) + abs(nexty - y) + dfs(p + d);
}

int main() {
  cin >> h >> w >> d;
  grid.resize(h * w + 2);
  rep(i, h)rep(j, w) {
    int a;
    cin >> a;
    grid[a] = P(i, j);
  }
  cost.resize(h * w + 2, INF);
  rep(i, h*w) dfs(i + 1);
  int q;
  cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    int ans = cost[l] - cost[r];
    printf("%d\n", ans);
  }

}