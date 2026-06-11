#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const ll N_MAX = 1e5 + 10;

ll N, C;
ll glid[501][501], discomfort[31][31], color_dist[3][31], cost[3][31];


void solve(){

  if(N == 1) {
    cout << 0 << endl;
    return;
  }

  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < N; j++){
      color_dist[(i + j)%3][glid[i][j]]++;
    }
  }

  for(ll i = 0; i < 3; i++){
    for(ll j = 0; j < C; j++){
      for(ll k = 0; k < C; k++){
        cost[i][j] += color_dist[i][k] * discomfort[k][j];
      }
    }
  }

  ll ans = 1e18;

  for(ll i = 0; i < C; i++){
    for(ll j = 0; j < C; j++){
      if(j == i) continue;
      for(ll k = 0; k < C; k++){
        if(k == i || k == j) continue;

        ans = min(ans, cost[0][i] + cost[1][j] + cost[2][k]);
        
      }
    }
  }

  cout << ans << endl;
}


int main() {

  memset(color_dist, 0, sizeof(color_dist));
  memset(cost, 0, sizeof(cost));

  cin >> N >> C;

  for(ll i = 0; i < C; i++){
    for(ll j = 0; j < C; j++){
      cin >> discomfort[i][j];
    }
  }

  for(ll i = 0; i < N; i++){
    for(ll j = 0; j < N; j++){
      cin >> glid[i][j];
      glid[i][j]--;
    }
  }

  solve();
}