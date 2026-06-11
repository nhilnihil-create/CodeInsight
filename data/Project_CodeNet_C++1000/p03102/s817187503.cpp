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
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(n);
  vector<vector<int>> a(n, vector<int>(m));
  rep(i,m) cin >> b[i];
  rep(i,n) rep(j,m) cin >> a[i][j];
  int ans = 0;
  rep(i,n) {
    int temp = 0;
    rep(j,m) temp += b[j] * a[i][j];
    if (temp + c > 0) ans++;
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}