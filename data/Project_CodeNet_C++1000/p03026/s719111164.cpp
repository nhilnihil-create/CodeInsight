#include <bits/stdc++.h>
#include <numeric>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define per(i,n) for (int i = n - 1; i >= 0; --i)
#define rep1(i,n) for (int i = 1; i <= n; ++i)
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline T intceil(T a, T b) { return (a + (b - 1)) / b; }
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const long long MOD = 1e9+7;
#define precout() cout << std::fixed << std::setprecision(20);
const string alphabet = "abcdefghijklmnopqrstuvwxyz";
const int dy[4] = { 0, 1, 0, -1 };
const int dx[4] = { 1, 0, -1, 0 };
static const double pi = 3.141592653589793;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<vector<int>> g(n);
  rep(i, n - 1) {
    int a,b; cin >> a >> b; --a,--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(c.begin(), c.end(), greater<int>());

  int cIdx = 1;
  queue<P> q;
  q.push({0, c[0]});
  int score = 0;
  vector<int> ans(n, 0);
  vector<bool> visited(n, 0);
  ans[0] = c[0];
  visited[0] = 1;

  while(!q.empty()) {
    auto cur = q.front(); q.pop();

    for(auto next:g[cur.first]) {
      if(visited[next]) continue;

      visited[next] = 1;
      int nextC = c[cIdx++];
      ans[next] = nextC;
      q.push({next, nextC});
      score += min(cur.second, nextC);
    }
  }

  cout << score << endl;
  rep(i, n) {
    cout << ans[i];
    if(i != n - 1) cout << " ";
  }
  cout << endl;
}
