#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define all(x) x.begin(), x.end()
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5 << 28, MOD = 1e9 + 7;

int N, Z, W;
vi A;
void input() {
  int x, y, z;
  cin >> N >> Z >> W;
  A.resize(N);
  rep(i, 0, N - 1) { cin >> A[i]; };
}
int dp[MX + 5][2];
void solve() {
  int ans = abs(W - A[N - 1]);
  if (N > 1) {
    ans = max(ans, (abs(A[N - 2] - A[N - 1])));
  }
  cout << ans << endl;
}
signed main() {
  input();
  solve();
  return 0;
}