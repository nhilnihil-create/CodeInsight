#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define INF 1e18L+5
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

void minSelf(ll& a, ll b){
  a = min(a, b);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vi v(n); for(auto& i: v) cin >> i;
  vvi dp(n, vi(n));
  auto sum = [&](const int& l, const int& r){
    ll res = 0;
    rep(i,l,r+1) res += v[i];
    return res;
  };
  rrep(l, n-1, 0){
    rep(r, l, n){
      if(l == r) dp[l][r] = 0;
      else{
        dp[l][r] = INF;
        ll s = sum(l, r);
        rep(i,l,r){
          minSelf(dp[l][r], dp[l][i] + dp[i+1][r] + s);
        }
      }
    }
  }
  cout << dp[0][n-1];
}
