#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  vector<string> s(h); rep(i,h) cin >> s[i];
  queue<pair<int,int>> q;
  q.push({0,0});
  vector<string> tmp = s;
  tmp[0][0] = '#';
  vector<vi> dist(h,vi(w));
  map<int,int> cnt;
  while(!q.empty()){
    pair<int,int> p = q.front(); q.pop();
    int x = p.second, y = p.first;
    rep(i,4){
      if(x+dx[i]<0 || w<=x+dx[i] || y+dy[i]<0 || h<=y+dy[i]) continue;
      if(tmp[y+dy[i]][x+dx[i]] == '.'){
        dist[y+dy[i]][x+dx[i]] += dist[y][x]+1;
        tmp[y+dy[i]][x+dx[i]] = '#';
        cnt[dist[y+dy[i]][x+dx[i]]]++;
        q.push({y+dy[i],x+dx[i]});
      }
    }
  }
  if(dist[h-1][w-1] == 0) cout << -1;
  else{
    int ans = 0;
    for(auto x : cnt){
      if(x.first <= dist[h-1][w-1]) ans += x.second-1;
      else ans += x.second;
    }
    rep(i,h) rep(j,w) if(s[i][j] != '#' && dist[i][j] == 0) ans++;
    cout << ans-1;
  }
  cout << "\n";
  return 0;
}
