#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll MOD = 1000000007;
const ll INF = 9999999999;
const int INFI=2147483647;
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
  T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }


int N,M;
Graph G;
vector<int> color;

bool dfs(int v){
  int c = color[v];
  bool ok = true;
  for (int nv : G[v]){
    if (color[nv] == c) return false;
    if (color[nv] != -1) continue;
    color[nv] = 1 - c;
    ok &= dfs(nv);
  }
  return ok;
}

int main() {
  cin >>N >>M;
  G.assign(N, vector<int>());
  rep(i, M){
    int a,b; cin >>a >>b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  color.assign(N, -1);
  color[0] = 0;
  bool ok = dfs(0); // 二部グラフかどうか
  ll black = 0, white = 0;
  rep(i, N){
    if (color[i] == 0) white++;
    else black++;
  }
  ll res;
  if (ok){
    // 二部グラフなら辺の数は(0の数)*(1の数)になる
    res = black * white;
  }else{
    // 二部グラフでないなら任意の頂点間に辺が存在する
    res = (ll)N * (ll)(N-1) / 2LL;
  }
  cout <<res - M <<endl;
}