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
  ll H, W;
  cin >> H >> W;
  vvl cij(10, vl(10));
  rep(i, 10){
    rep(j, 10){
      cin >> cij[i][j];
    }
  }
  vvl A(H, vl(W));
  rep(i, H){
    rep(j, W){
      cin >> A[i][j];
    }
  }

  vl cost(10, 1000000);
  cost[1] = 0;

  rep(i, 10){
    if(i == 1) continue;

    vl dist(10, 100000);
    vl vis(10, 0);

    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({cij[i][i], i});

    while(!que.empty()){
      pll top = que.top();
      que.pop();
      if(vis[top.second] == 1) continue;
      vis[top.second] = 1;

      rep(j, 10){
	if(vis[j] == 1) continue;
	dist[j] = min(dist[j], top.first + cij[top.second][j]);
	que.push({dist[j], j});
      }
    }

    cost[i] = dist[1];
  }

  ll ans = 0;
  rep(i, H){
    rep(j, W){
      if(A[i][j] != -1) ans += cost[A[i][j]];
    }
  }

  cout << ans << endl;
  
  return 0;
}
