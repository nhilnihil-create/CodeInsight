#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

int n, m;
string s;
vector<int> G[200200];

int cnt[200200][2];
bool visited[200200];

void deg(int v) {
  for (int u: G[v]) {
    cnt[v][s[u] - 'A']++;
  }
}

void solve() {
  queue<int> q;
  rep(i, n) {
    if (cnt[i][0] == 0 || cnt[i][1] == 0) {
      q.push(i);
    }
  }
  while (q.size()) {
    int v = q.front();
    q.pop();
    if (visited[v]) continue;
    visited[v] = true;
    cnt[v][0] = 0;
    cnt[v][1] = 0;
    for (int u: G[v]) {
      if (u == v) continue;
      if (visited[u]) continue;
      if (--cnt[u][s[v] - 'A'] == 0) q.push(u);
    }
  }
  rep(v, n) {
    if (cnt[v][0] || cnt[v][1]) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  cin >> n >> m;
  cin >> s;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    if (a != b) G[b].push_back(a);
  }

  rep(i, n) deg(i);
  solve();




  
  return 0;
}