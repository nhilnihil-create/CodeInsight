#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int h,w; cin >> h >> w;
  vector<string> a(h); rep(i,h) cin >> a[i];
  int ans = 0;
  queue<pair<int,int>> q1,q2;
  rep(i,h) rep(j,w) if(a[i][j] == '#') q2.push({i,j});
  while(!q2.empty()){
    ans++;
    while(!q2.empty()){
      q1.push(q2.front());
      q2.pop();
    }
    while(!q1.empty()){
      auto now = q1.front(); q1.pop();
      int y = now.first, x = now.second;
      rep(i,4){
        if(x+dx[i]<0 || w<=x+dx[i] || y+dy[i]<0 || h<=y+dy[i]) continue;
        if(a[y+dy[i]][x+dx[i]] == '.'){
          a[y+dy[i]][x+dx[i]] = '#';
          q2.push({y+dy[i],x+dx[i]});
        }
      }
    }
  }
  cout << ans-1;
  cout << "\n";
  return 0;
}
