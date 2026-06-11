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

const int MOD = 1e9+7;

void addSelf(int& a, int b){
  a += b;
  if(a >= MOD) a -= MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n; cin >> n;
  vvi v(n, vi(n));
  rep(i,0,n) rep(j,0,n) cin >> v[i][j];
  vi dp(1 << n);
  dp[0] = 1;
  rep(used,0,(1<<n)-1){
    int a = __builtin_popcount(used);
    rep(b,0,n){
      if(v[a][b] && !(used & (1 << b))){
        int m2 = used ^ (1 << b);
        addSelf(dp[m2], dp[used]);
      }
    }
  }
  cout << dp[(1<<n)-1];
}
