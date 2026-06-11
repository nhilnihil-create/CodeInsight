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
  int N, M; cin >> N >> M;
  pii e[M];
  vector<vector<int>> G(N);
  rep(i,M){
    int a, b; cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
    e[i] = {a,b};
  }


  int cnt = 0;
  rep(i,M){
    queue<int> q;
    q.push(0);
    bool connected[N] = {};
    while (!q.empty()){
      int v = q.front(); q.pop();
      connected[v] = true;
      for (int next_v : G[v]){
        if ((e[i].first==v && e[i].second==next_v) || (e[i].first==next_v && e[i].second==v)) continue;
        if (connected[next_v]) continue;
        q.push(next_v);
      }
    }

    rep(i,N) {
      if (connected[i]==0) {
        cnt++;
        break;
      }
    }
  }

  cout << cnt << endl;

  
  // cout << fixed << setprecision(10);
  
  return 0;
}
