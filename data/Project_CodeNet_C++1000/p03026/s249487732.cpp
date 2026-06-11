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

vector<int> c, ans;

const int MAX = 1e4;
vector<int> G[MAX];
int t = 0;

void dfs(int v, int p = -1) {
  ans[v] = c[t++];
  for (int u: G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
}

int main() {
  int n;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  c.resize(n);
  rep(i, n) cin >> c[i];
  
  sort(c.begin(), c.end(), greater<int>());
  int score = accumulate(c.begin(), c.end(), 0) - c[0];
  ans.resize(n);
  dfs(0);
  cout << score << endl;
  rep(i, n) cout << ans[i] << (i == n - 1 ? '\n' : ' ');



  
  return 0;
}