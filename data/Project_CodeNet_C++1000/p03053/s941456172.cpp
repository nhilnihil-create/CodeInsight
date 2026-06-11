#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};



int main() {
  int h,w;
  cin>>h>>w;
  vector<vector<int>> dist(h,vin(w,0));
  vector<string> a(h);
  rep(i,0,h)cin>>a[i];
  queue<pair<int, int>> que;
  rep(i,0,h){
   rep(j,0,w){
     if(a[i][j]=='#'){
      que.push(mp(i,j)); 
     }
   }
  }
  while (que.size() != 0) {              // キューの要素がなくなったら終了
        pair<int, int> now = que.front();  // 現在の状態
        que.pop();
        for (int i = 0; i < 4; i++) {
            int ny = now.first + dy[i];                            // 次の探索場所の行番号
            int nx = now.second + dx[i];                           // 次の探索場所の列番号
            if (ny < 0 || h <= ny || nx < 0 || w <= nx) continue;  // 迷路の外に出るならスルー
            if (a[ny][nx] == '#') continue;                     // 障害物があればスルー
            if (dist[ny][nx] != 0) continue;                     //探索済みならスルー
            que.push(make_pair(ny, nx));
            dist[ny][nx] = dist[now.first][now.second] + 1;
        }
    }
  
  int ans=0;
  rep(i,0,h){
   rep(j,0,w){
     chmax(ans,dist[i][j]);
   }
  }
  cout<<ans<<endl;
}
