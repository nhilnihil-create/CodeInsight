#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;

int main() {

  int H, W;
  cin >> H >> W;

  vector<vector<int>> maze(H+2, vector<int>(W+2));
  vector<vector<int>> dist(H+2, vector<int>(W+2));

  REP(h,H+2){
    REP(w,W+2){
      dist[h][w] = H*W*1000;
      maze[h][w] = 1;
    }
  }
  dist[1][1] = 1;


  REP(h,H){
    REP(w,W){
      char ctmp;
      cin >> ctmp;
      if (ctmp == '.') maze[h+1][w+1] = 0;
    }
  }

  deque<vector<int>> deq;
  vector<int> vtmpinitial(2);
  vtmpinitial[0] = 1;
  vtmpinitial[1] = 1;
  deq.push_back(vtmpinitial);

  //  Breadth First Search
  while(! deq.empty()){
    vector<int> vtmp(2);
    int x, y;

    x = deq[0][0];
    y = deq[0][1];
    deq.pop_front();

    int nextx, nexty;
    nextx = x-1;
    nexty = y;
    if (maze[nextx][nexty] == 0){
      if(dist[nextx][nexty] > dist[x][y]+1){
        dist[nextx][nexty] = dist[x][y]+1;
        vtmp[0] = nextx;
        vtmp[1] = nexty;
        deq.push_back(vtmp);
      }
    }

    nextx = x+1;
    nexty = y;
    if (maze[nextx][nexty] == 0){
      if(dist[nextx][nexty] > dist[x][y]+1){
        dist[nextx][nexty] = dist[x][y]+1;
        vtmp[0] = nextx;
        vtmp[1] = nexty;
        deq.push_back(vtmp);
      }
    }

    nextx = x;
    nexty = y-1;
    if (maze[nextx][nexty] == 0){
      if(dist[nextx][nexty] > dist[x][y]+1){
        dist[nextx][nexty] = dist[x][y]+1;
        vtmp[0] = nextx;
        vtmp[1] = nexty;
        deq.push_back(vtmp);
      }
    }

    nextx = x;
    nexty = y+1;
    if (maze[nextx][nexty] == 0){
      if(dist[nextx][nexty] > dist[x][y]+1){
        dist[nextx][nexty] = dist[x][y]+1;
        vtmp[0] = nextx;
        vtmp[1] = nexty;
        deq.push_back(vtmp);
      }
    }

  }



  if (dist[H][W] == H*W*1000){
    cout << -1 << endl;
  } else{
    int ans = H*W;
    REP(h,H){
      REP(w,W){
        if (maze[h+1][w+1] == 1) ans-=1;
      }
    }
    ans -= dist[H][W];
    cout << ans << endl;
  }

}
