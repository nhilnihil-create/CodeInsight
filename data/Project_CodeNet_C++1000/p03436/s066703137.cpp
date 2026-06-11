#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int MOD = 1000000007;

int main() {
  int H,W;
  cin >> H >> W;
  vector<string> maze(H);
  rep(i,H){
    cin >> maze.at(i);
  }
  //BFS
  vector<vector<int>> dist(H,vector<int>(W,-1));
  dist.at(0).at(0) = 0;
  queue<pair<int,int>> que;
  pair<int,int> start = make_pair(0,0);
  que.push(start);
  while(!que.empty()){
    pair<int,int> p = que.front();
    que.pop();
    int pf = p.first;
    int ps = p.second;
    if(pf>0){
      if(maze.at(pf-1).at(ps) == '.' && dist.at(pf-1).at(ps) == -1){
        pair<int,int> pa = make_pair(pf-1,ps);
        que.push(pa);
        dist.at(pf-1).at(ps) = dist.at(pf).at(ps)+1;
      }
    }
    if(ps>0){
      if(maze.at(pf).at(ps-1) == '.' && dist.at(pf).at(ps-1) == -1){
        pair<int,int> pb = make_pair(pf,ps-1);
        que.push(pb);
        dist.at(pf).at(ps-1) = dist.at(pf).at(ps)+1;
      }
    }
    if(pf<H-1){
      if(maze.at(pf+1).at(ps) == '.' && dist.at(pf+1).at(ps) == -1){
        pair<int,int> pc = make_pair(pf+1,ps);
        que.push(pc);
        dist.at(pf+1).at(ps) = dist.at(pf).at(ps)+1;
      }
    }
    if(ps<W-1){
      if(maze.at(pf).at(ps+1) == '.' && dist.at(pf).at(ps+1) == -1){
        pair<int,int> pd = make_pair(pf,ps+1);
        que.push(pd);
        dist.at(pf).at(ps+1) = dist.at(pf).at(ps)+1;
      }
    }
  }
  int ans = H*W - dist.at(H-1).at(W-1);
  rep(i,H){
    rep(j,W){
      if(maze.at(i).at(j) == '#'){
        ans--;
      }
    }
  }
  if(dist.at(H-1).at(W-1) == -1){
    cout << -1 << endl;
  }
  else{
    cout << ans-1 << endl;
  }
}