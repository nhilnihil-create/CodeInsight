#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll,ll>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};

int main(){
  ll H,W;
  cin >> H >> W;
  vector<string> A(H);
  REP(i, H) cin >> A[i];
  
  vector<P> vec;

  REP(i,H){
    REP(j,W){
      if(A.at(i).at(j)=='#'){
        vec.push_back(make_pair(i,j));
      }
    }
  }

  queue<P> que;
  vector<vector<ll>> dist(H,vector<ll> (W,-1));
  for(auto x:vec){
    que.push(x);
    dist[x.first][x.second]=0;
  }

  while(!que.empty()){
    ll vy = que.front().first;
    ll vx = que.front().second;
    que.pop();

    REP(k,4){
      ll nvy = vy+dy[k];
      ll nvx = vx+dx[k];
      if(nvy<0||nvy>H-1||nvx<0||nvx>W-1||dist[nvy][nvx]!=-1||A[nvy][nvx]=='#'){
        continue;
      }

      dist[nvy][nvx]=dist[vy][vx]+1;
      que.push(make_pair(nvy,nvx));
    }
  }

  ll MAX = 0;
  REP(i,H){
    REP(j,W){
      if(A[i][j]=='.'){
        chmax(MAX,dist[i][j]);
      }
    }
  }

  cout << MAX << endl;
}