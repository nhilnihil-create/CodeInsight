#include <bits/stdc++.h>
using namespace std;

int dh[4] = {1,0,-1,0};
int dw[4] = {0,1,0,-1};

int main(){
  int H,W;
  cin >> H >> W;

  vector<string> m(H);
  int cnt = 0;
  for (int i = 0; i < H; i++)
  {
    cin >> m[i];
    for (int j = 0; j < W; j++)
    {
      if(m[i][j]=='.') cnt++;
    }
  }

  vector<vector<int>> dist(H,vector<int>(W,-1));
  dist[0][0] = 0;
  queue<pair<int,int>> q;
  q.emplace(0,0);
  while(!q.empty()){
    pair<int,int> now = q.front();
    int nowh = now.first;
    int noww = now.second;
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      int nexth = nowh + dh[i];
      int nextw = noww + dw[i];
      if(nexth >= H || nexth < 0 || nextw >= W || nextw < 0) continue;
      if(m[nexth][nextw]=='#') continue;
      if(dist[nexth][nextw]!=-1) continue;
      dist[nexth][nextw] = dist[nowh][noww] + 1;
      q.emplace(nexth,nextw);
    }
  }
  if(dist[H-1][W-1]==-1) cout << -1 << endl;
  else cout << cnt-dist[H-1][W-1]-1 << endl;  
}