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

void addSelf(int &a, int b){
  a += b;
  if(a >= MOD) a -= MOD;
  if(a < 0) a += MOD;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n,k; cin >> n >> k;
  vi dp(k+1); dp[0] = 1;
  rep(i,0,n){
    int up; cin >> up;
    vi delta(k+1);
    rrep(j,k,0){
      int a = j + 1;
      int b = j + min(up, k-j);
      int tmp = dp[j];
      if(a <= b){
        addSelf(delta[a], tmp);
        if(b+1 <= k)
          addSelf(delta[b+1], -tmp);
      }
    }
    int inc = 0;
    rep(j,1,k+1){
      addSelf(inc, delta[j]);
      addSelf(dp[j],inc);
    }
  }
  cout << dp[k];
}
