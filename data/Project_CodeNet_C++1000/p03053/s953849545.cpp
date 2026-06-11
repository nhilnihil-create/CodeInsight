#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

//vector出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v){
  o<<"{";
  for(int i=0;i<(int)v.size();i++) o << (i>0?", ":"") << v[i];
  o<<"}";
  return o;
}




int main() {
  int H,W;
  cin >> H >> W;
  vector<string> A(H);
  vector<vector<int>> grid(H,vector<int>(W,-1));
  queue<vector<int>> q;
  rep(i,H) {
    cin >> A[i];
    rep(j,W) if (A[i][j]=='#') {
      grid[i][j]=0;
      q.push({i,j,0});
    }
  }

  int res = 0;
  while (!q.empty()) {
    auto t = q.front();
    int y = t[0],x = t[1];
    q.pop();
    if (x>0) if (grid[y][x-1]==-1) {
      grid[y][x-1] = t[2]+1;
      q.push({y,x-1,t[2]+1});
    }
    if (y>0) if (grid[y-1][x]==-1) {
      grid[y-1][x] = t[2]+1;
      q.push({y-1,x,t[2]+1});
    }
    if (x<W-1) if (grid[y][x+1]==-1) {
      grid[y][x+1] = t[2] + 1;
      q.push({y,x+1,t[2]+1});
    }
    if (y<H-1) if (grid[y+1][x]==-1) {
      grid[y+1][x] = t[2] + 1;
      q.push({y+1,x,t[2]+1});
    }
    chmax(res,t[2]);
  }
  cout << res << endl;
}