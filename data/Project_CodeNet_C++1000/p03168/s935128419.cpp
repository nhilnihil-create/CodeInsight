#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vector<double> dp(n+1);
  dp[0] = 1.0;
  rep(i,0,n){
    double d; cin >> d;
    rrep(j,i+1,0)
      dp[j] = (j ? dp[j-1] * d : 0) + dp[j] * (1-d);
  }
  double ans = 0.0;
  rep(i,n/2+1,n+1) ans += dp[i];
  cout << fixed << setprecision(10) << ans << "\n";
}
