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
typedef pair<ll, ll> pll;
typedef pair<unsigned char, unsigned char> pcc;
typedef pair<double, double> pdd;
typedef vector<vector<ll>> matrix;

pll d[1000000];
int parent[1000000];
int treesz[1000000];
ll dp[1000000];
int n;
int s;

vector<int> edges[1000000];
void check() {
  memset(dp, 0, sizeof(dp));
  queue<pii> q;
  q.push({s, -1});
  ll amt = 0;
  while(!q.empty()) {
    pii curr = q.front(); q.pop();
    amt += dp[curr.first];
    for(int out: edges[curr.first]) {
      if(out == curr.second) continue;
      dp[out] = dp[curr.first]+1;
      q.push({out, curr.first});
    }
  }
  if(amt != d[0].first) {
    cout << "-1\n";
    exit(0);
  }
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d, d+n);
  map<ll, int> from;
  for(int i = 0; i < n; i++) from[d[i].first] = i;
  for(int i = 0; i < n; i++) treesz[i] = 1;
  for(int qq = n-1; qq > 0; qq--) {
    int realVertex = d[qq].second;
    ll currDist = d[qq].first;
    ll want = currDist - n + 2 * treesz[realVertex];
    if(!from.count(want)) {
      cout << "-1\n";
      return;
    }
    int fromInD = from[want];
    int actualVertex = d[fromInD].second;
    if(actualVertex == realVertex) {
      cout << "-1\n";
      return;
    }
    parent[realVertex] = actualVertex;
    edges[realVertex].push_back(actualVertex);
    edges[actualVertex].push_back(realVertex);
    treesz[actualVertex] += treesz[realVertex];
    s = actualVertex;
  }
  check();
  for(int i = 0; i < n; i++) {
    for(int out: edges[i]) {
      if(out > i) {
        cout << (i+1) << " " << (out+1) << "\n";
      }
    }
  }
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
