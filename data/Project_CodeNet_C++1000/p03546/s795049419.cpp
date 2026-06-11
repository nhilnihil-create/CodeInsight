#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

void warshall_floyd(vector<vector<int>>& G, ll n){
  for (int k = 0; k < n; ++k){      //経由する頂点
    for (int i = 0; i < n; ++i){    //始点
      for (int j = 0; j < n; ++j){  //終点
        G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
      }
    }
  }
}

int main(){
  int H, W; cin >> H >> W;
  vector<vector<int>> c(10, vector<int>(10));
  rep(i, 10) rep(j, 10) cin >> c[i][j];

  map<int, int> mp;
  rep(i, H) rep(j, W) {
    int a; cin >> a;
    mp[a]++;
  }
  warshall_floyd(c, 10);
  ll ans = 0;
  for (auto p: mp){
    if (p.first == -1) continue;
    ans += c[p.first][1] * p.second;
  }
  cout << ans << endl;
}
