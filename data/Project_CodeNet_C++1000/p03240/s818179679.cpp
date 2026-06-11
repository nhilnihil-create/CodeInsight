#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int INF = 1001001001;

int main(){
  int n;
  cin >> n;
  int hig[n][101][101];
  vector<vector<int>> least(101, vector<int>(101,INF));
  for(int i=0; i<n; ++i){
    int x, y, h;
    cin >> x >> y >> h;
    if(h == 0){
      for(int j=0; j<=100; ++j) for(int k=0; k<=100; ++k){
        least[j][k] = min(least[j][k], abs(j-x) +abs(k-y));
      }
    }
    else for(int j=0; j<=100; ++j) for(int k=0; k<=100; ++k){
      hig[i][j][k] = h +abs(j-x) +abs(k-y);
    }
  }
  for(int i=0; i<=100; ++i) for(int j=0; j<=100; ++j){
    bool ansis = true;
    int ansh = 0;
    for(int k=1; k<n; ++k){
      ansh = max(ansh, hig[k][i][j]);
      if(hig[k][i][j] == 0 || hig[k-1][i][j] == 0) continue;
      if(hig[k-1][i][j] != hig[k][i][j]) ansis = false;
    }
    if(ansh > least[i][j]) continue;
    if(ansis){
      printf("%d %d %d\n", i, j, ansh);
      return 0;
    }
  }
}