#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;

int main(){
  int N; cin >> N;
  vector<vector<pii>> G(N);
  rep(i,N-1) {
    int u, v, w; cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({v,w&1});
    G[v].push_back({u,w&1});
  }

  vector<int> c(N,-1);
  queue<int> q;
  q.push(0);
  c[0] = 0;
  while(!q.empty()){
    int now = q.front(); q.pop();
    for (auto e : G[now]){
      int n = e.first;
      int d = e.second;
      if (c[n]!=-1) continue; 
      c[n] = (c[now] + d)%2;
      q.push(n);
    }
  }
  rep(i,N) cout << c[i] << endl;
  // cout << fixed << setprecision(10);
  
  return 0;
}
