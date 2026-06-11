#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
  int h,w;
  cin >> h >> w;
  vector<vector<char>> a(h,vector<char>(w));
  rep(i,h){
    rep(j,w){
      cin >> a.at(i).at(j);
    }
  }
  vector<vector<int>> te(h,vector<int>(w,-1));
  queue<pair<int,int>> q;
  rep(i,h){
    rep(j,w){
      if(a.at(i).at(j)=='#'){
        q.push(make_pair(i,j));
        te.at(i).at(j)=0;
      }
    }
  }
  while(q.size()){
    auto z=q.front();
    q.pop();
    rep(i,4){
      int nx=dx[i]+z.first;
      int ny=dy[i]+z.second;
      if(!(nx>=0&&ny>=0&&nx<h&&ny<w))
        continue;
      if(te.at(nx).at(ny)!=-1)
        continue;
      q.push(make_pair(nx,ny));
      te.at(nx).at(ny)=te.at(z.first).at(z.second)+1;
    }
  }
  int m=0;
  rep(i,h){
    rep(j,w){
      m=max(m,te.at(i).at(j));
    }
  }
  cout << m << endl;
}