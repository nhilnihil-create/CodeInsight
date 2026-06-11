#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  int h,w;
  cin >> h >> w;
  vs d(h);
  int cnt = 0;
  rep(i,h){
    cin >> d.at(i);
    rep(j,w){
      cnt += (d.at(i).at(j) == '.');
    }
  }
  queue<pii> que;
  que.push(pii(0,0));
  vector<vl> dist(h, vl(w, -1));
  dist.at(0).at(0) = 0;
  while(que.size()){
    pii P = que.front();
    que.pop();
    rep(i,4){
      int nx,ny;
      nx = P.first + dx[i];
      ny = P.second + dy[i];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(d.at(nx).at(ny) == '#') continue;
      if(dist.at(nx).at(ny) == -1){
        dist.at(nx).at(ny) = dist.at(P.first).at(P.second) + 1;
        que.push(pii(nx,ny));
      }
    }
  }
  if(dist.at(h-1).at(w-1) == -1) cout << -1 << endl;
  else{
    cout << cnt - (dist.at(h-1).at(w-1) + 1) << endl;
  }
}

