#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for (int i = 0; i < (n); i++)
typedef pair<int,int> P;
const int INF = 100000000;

int W,H;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

bool movable(vector<vector<char>> &c, vector<vector<int>> &mat, int h, int w) {
  if ((h<0) || (h>=H) || (w<0) || (w>=W)) {
    return false;
  }
  else if (mat[h][w]!=INF || (c[h][w]=='#')) {
    return false;
  }
  else {
    return true;
  }
}


int bfs(vector<vector<char>> &c, vector<vector<int>> &mat) {

  queue<P> que;
  
  rep(h,H) {
      rep(w,W) {
          if(c[h][w]=='#') {
              que.push(P(h,w));
              mat[h][w] = 0;
          }
      }
  }

  while(que.size()) {
    P p = que.front();
    que.pop();

    rep(i,4){
      if (movable(c,mat,p.first+dy[i],p.second+dx[i])) {
        que.push(P(p.first+dy[i],p.second+dx[i]));
        mat[p.first+dy[i]][p.second+dx[i]]=mat[p.first][p.second]+1;
      }
    }
  }
  return 0;
}

int main() {
  int black = 0;
  cin >> H >> W;

  vector<vector<char>> c(H,vector<char> (W));
  
  rep(h,H) {
    rep(w,W) {
      cin >> c[h][w]; 
      if (c[h][w] == '#') {
        black++;
      }
    }
  }

  vector<vector<int>> mat(H,vector<int> (W, INF));
  int ans = bfs(c,mat);
  ans = 0;
  rep(h,H) {
    rep(w,W) {
      if (mat[h][w] > ans) {
        ans = mat[h][w];
      }
    }
  } 
  cout << ans << endl;
}