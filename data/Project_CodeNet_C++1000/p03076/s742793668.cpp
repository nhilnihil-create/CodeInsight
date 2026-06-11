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
  int n = 5;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int d = 10;
  rep(i,n) if (v[i] % 10 != 0) d = min(d, v[i] % 10);
  int ans = d;
  rep(i,n) {
    if (v[i] % 10 == 0) ans += v[i];
    else ans += v[i] / 10 * 10 + 10;
  }
  ans -= 10;
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}