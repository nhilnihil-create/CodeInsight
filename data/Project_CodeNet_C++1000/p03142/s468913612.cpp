#include<bits/stdc++.h>
#define endl '\n';
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------


int main(){
  int N,M;
  cin >> N >> M;
  vector<int> A(N+M-1),B(N+M-1);
  vector<vector<int>> G(N);
  vector<int> in(N,0);
  rep(i,N+M-1){
    cin >> A[i] >> B[i];
    A[i]--;
    B[i]--;
    G[A[i]].push_back(B[i]);
    in[B[i]]++;
  }
  int p = -1;
  rep(i,N) if(!in[i]) p = i;
  queue<int> que;
  que.push(p);
  vector<int> dist(N,-1);
  dist[p] = 0;
  while(que.size()){
    int v = que.front();
    que.pop();
    for(int nv: G[v]){
      chmax(dist[nv],dist[v]+1);
      in[nv]--;
      if(in[nv] == 0) que.push(nv);
    }
  }
  vector<int> par(N);
  par[p] = -1;
  rep(i,N+M-1){
    if(dist[B[i]]-dist[A[i]] == 1){
      par[B[i]] = A[i];
    }
  }
  rep(i,N){
    cout << par[i]+1 << endl;
  }
  return 0;
}