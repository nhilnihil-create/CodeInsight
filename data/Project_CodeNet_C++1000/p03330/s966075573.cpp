#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define rep_inv(i, n, m) for(int i = (int)(n); i > (int)(m); i--)
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vl>;
using vvc = vector<vc>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

void dfs(vvl change, ll depth, ll tot, vl &used, ll &ans){
  if(depth == 3){
    ans = min(ans, tot);
    return;
  }

  rep(i, change[depth].size()){
    if(used[i] == 1) continue;

    used[i] = 1;
    dfs(change, depth + 1, tot + change[depth][i], used, ans);
    used[i] = 0;
  }
}

int main(){
  ll N, C;
  cin >> N >> C;
  vvl D(C, vl(C));
  rep(i, C){
    rep(j, C){
      cin >> D[i][j];
    }
  }
  vvl c(N, vl(N));
  rep(i, N){
    rep(j, N){
      cin >> c[i][j];
    }
  }

  vvl change(3, vl(C, 0));
  rep(i, N){
    rep(j, N){
      rep(k, C) change[(i + j) % 3][k] += D[c[i][j] - 1][k];
    }
  }

  /*
  cout << endl;
  
  rep(j, C){
    rep(i, 3){
      cout << change[i][j] << ' ';
    }
    cout << endl;
  }
  */

  vl used(C, 0);
  ll ans = (ll)pow(10, 18);
  dfs(change, 0, 0, used, ans);

  cout << ans << endl;
  
  return 0;
}
