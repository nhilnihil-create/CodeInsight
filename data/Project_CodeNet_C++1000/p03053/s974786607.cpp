#include <bits/stdc++.h>
using namespace std;

const vector<pair<int, int>> DIFFs = {{1,0},{-1,0},{0,1},{0,-1}};
const int INF = 1e9;

int main() {
  int H, W;
  cin >> H >> W;

  int squeres[H][W];
  vector<pair<int, int>> blacks;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char A;
      cin >> A;
      
      if(A=='#') {
        blacks.push_back({i,j});
        squeres[i][j]=-1;
      } else {
        squeres[i][j]=INF;
      }
    }
  }

  queue<tuple<int, int, int>> q; //count, h, w;
  for (auto b: blacks) {
    int h = b.first;
    int w = b.second;
    q.push(make_tuple(0,h,w));
  }

  int ans = 0;
  while (!q.empty()) {
    int count, h, w;
    tie(count, h, w) = q.front();
    q.pop();
    if (squeres[h][w] < count && squeres[h][w]!=-1) continue;

    ans = max(ans, count);
    for(auto diff: DIFFs) {
      int dh = diff.first;
      int dw = diff.second;
      if ( 0<=h+dh && h+dh < H &&
           0<=w+dw && w+dw < W &&
           squeres[h+dh][w+dw] !=-1 &&
           squeres[h+dh][w+dw] > count+1 
           ) {
             squeres[h+dh][w+dw]=count+1;
             q.push(make_tuple(count+1, h+dh, w+dw));
      }
    }
  }

  cout << ans << endl;

  return 0;
}