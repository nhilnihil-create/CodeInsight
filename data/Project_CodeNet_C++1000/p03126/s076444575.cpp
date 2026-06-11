#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n);
  rep(i,n) {
    int k;
    cin >> k;
    v[i].resize(k);
    rep(j,k) cin >> v[i][j];
  }
  vector<int> ans(m);
  for (vector<int> u: v) {
    for (int i: u) {
      ans[i-1]++;
    }
  }
  int res = 0;
  rep(i,m) {
    if (ans[i] == n) res++;
  }
  cout << res << endl;
}

int main() {
  solve();
  return 0;
}