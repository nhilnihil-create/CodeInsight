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
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

int n,m;
vector<int> edges[100005];
int dp[100005];
void solve() {
  cin >> n >> m;
  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  queue<int> q;
  q.push(1);
  dp[1] = 1;
  while(!q.empty()) {
    int curr = q.front(); q.pop();
    for(int out: edges[curr]) {
      if(dp[out] == dp[curr]) {
        cout << n*(n-1LL) / 2 - m << "\n";
        return;
      }
      if(dp[out] == 0) {
        dp[out] = -dp[curr];
        q.push(out);
      }
    }
  }
  ll a = 0;
  ll b = 0;
  for(int i = 1; i <= n; i++) {
    (dp[i] > 0 ? a : b)++;
  }
  cout << a*b - m << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ":" << "\n";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
