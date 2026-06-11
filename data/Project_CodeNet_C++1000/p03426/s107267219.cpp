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

int main(){
  ll H, W, D;
  cin >> H >> W >> D;
  ll A;
  vpll pos(H*W + 1);
  rep(i, H){
    rep(j, W){
      cin >> A;
      pos[A] = {i + 1, j + 1};
    }
  }
  ll Q;
  cin >> Q;
  vl L(Q), R(Q);
  rep(i, Q) cin >> L[i] >> R[i];

  vl cost(H*W + 1);

  rep2(i, 1, D + 1){
    cost[i] = 0;
    ll move = i + D;
    
    while(move <= H*W){
      cost[move] = cost[move - D] + abs(pos[move].first - pos[move - D].first) + abs(pos[move].second - pos[move - D].second);
      move += D;
    }
  }

  rep(i, Q) cout << cost[R[i]] - cost[L[i]] << endl;
  
  return 0;
}
