#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

ll MOD = 1e9+7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int r, c; cin >> r >> c;
  vector<string> v(r);
  rep(i,0,r) cin >> v[i];
  vector<vector<ll>> res(r, vector<ll>(c));
  res[0][0] = 1;
  rep(i,0,r){
    rep(j,0,c){
      if(v[i][j] == '#') continue;
      if(i > 0) res[i][j] = (res[i][j] + res[i-1][j]) % MOD;
      if(j > 0) res[i][j] = (res[i][j] + res[i][j-1]) % MOD;
    }
  }
  cout << res[r-1][c-1] << "\n";
}
