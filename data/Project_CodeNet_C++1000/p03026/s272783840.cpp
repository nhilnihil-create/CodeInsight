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
  int N;
  cin >> N;
  vector<set<int>> G(N);
  rep(i,N-1){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    G[a].insert(b);
    G[b].insert(a);
  }
  vector<int> c(N);
  rep(i,N){
    cin >> c[i];
  }
  sort(c.begin(),c.end(),greater<int>());
  queue<int> que;
  rep(i,N){
    if(G[i].size() == 1){
      que.push(i);
    }
  }
  ll sum = 0;
  for(int i=1; i<N; i++){
    sum += c[i];
  }
  vector<int> ans(N);
  while(que.size()){
    if(!c.size()) break;
    int v = que.front();
    que.pop();
    ans[v] = c.back();
    c.pop_back();
    int nv = *G[v].begin();
    G[nv].erase(v);
    if(G[nv].size() == 1){
      que.push(nv);
    }
  }
  cout << sum << endl;
  rep(i,N){
    cout << ans[i] << (i!=N-1 ? " " : "\n");
  }
  return 0;
}
