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

int div2(int x) {
  if (x % 2 == 1) return 0;
  else return div2(x / 2) + 1;
}

void solve() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];
  int ans = INF;
  rep(i,n) ans = min(ans, div2(v[i]));
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}