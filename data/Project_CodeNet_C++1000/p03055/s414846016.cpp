#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef vector<vector<ll>> matrix;

vector<int> edges[200005];
int dp[200005];
int n;
int dist;

int bfs(int s) {
  for(int i = 1; i <= n; i++) dp[i] = 1e9;
  dp[s] = 0;
  queue<int> q;
  int last = -1, curr;
  q.push(s);
  while(!q.empty()) {
    last = (curr = q.front());
    q.pop();
    dist = dp[last];
    for(int out: edges[curr]) {
      if(dp[out] == 1e9) {
        dp[out] = 1 + dp[curr];
        q.push(out);
      }
    }
  }
  return last;
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  bfs(bfs(1));
  if(dist % 3 == 1) cout << "Second\n";
  else cout << "First\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
